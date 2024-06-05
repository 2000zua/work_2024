#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "json.hpp"

// Para conveniência
using json = nlohmann::json;

// Estrutura para armazenar os significados e sinônimos
struct DictionaryEntry {
    std::map<int, std::vector<std::string>> meanings;
    std::vector<std::string> synonyms;
};

// menu
int menu(){
    int opt;
    std::cout << "========================================================================" << std::endl;
    std::cout << "=============================== MENU ===================================" << std::endl;
    std::cout << "========================================================================" << std::endl;
    std::cout << "\t1: Binary Search" << std::endl;
    std::cout << "\t2: Binary Search" << std::endl;
    std::cout << "\t3: Binary Search" << std::endl;
    std::cout << "\t4: Binary Search" << std::endl;
    std::cout << "\t5: Binary Search" << std::endl;
    std::cout << "\t6: Exit" << std::endl;
    std::cout << "\t : Choose your options: ";
    std::cin >> opt;
    return opt;
}

// Função de busca binária em um dicionário ordenado
std::string binary_search(const std::map<std::string, DictionaryEntry>& dictionary, const std::string& target) {
    auto left = dictionary.begin();
    auto right = --dictionary.end();

    while (std::distance(left, right) >= 0) {
        auto mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        if (mid->first == target) {
            std::string result = "MEANINGS:\n \t* ";
            for (const auto& meaning : mid->second.meanings) {
                result += std::to_string(meaning.first) + ": ";
                for (const auto& item : meaning.second) {
                    result += item + "; \n \t* ";
                }
                result.pop_back();
                result.pop_back();
                result += "\n";
            }

            result += "SYNONYMS: \n \t* ";
            for (const auto& synonym : mid->second.synonyms) {
                result += synonym + "; \n \t* ";
            }
            result.pop_back();
            result.pop_back();
            result += "\n";

            return result;
        } else if (mid->first < target) {
            left = ++mid;
        } else {
            right = --mid;
        }
    }

    return "Not Found";  // Retorna "Not Found" se a chave não for encontrada
}

// Função para carregar o dicionário a partir de um arquivo JSON
std::map<std::string, DictionaryEntry> load_dictionary(const std::string& filename) {
    std::map<std::string, DictionaryEntry> dictionary;
    std::ifstream file(filename);
    json j;

    if (file.is_open()) {
        file >> j;
        for (json::iterator it = j.begin(); it != j.end(); ++it) {
            DictionaryEntry entry;
            for (json::iterator mit = it.value()["MEANINGS"].begin(); mit != it.value()["MEANINGS"].end(); ++mit) {
                int key = std::stoi(mit.key());
                std::vector<std::string> meanings;
                for (const auto& val : mit.value()) {
                    if (val.is_string()) {
                        meanings.push_back(val);
                    } else if (val.is_array()) {
                        for (const auto& subval : val) {
                            meanings.push_back(subval);
                        }
                    }
                }
                entry.meanings[key] = meanings;
            }

            for (const auto& synonym : it.value()["SYNONYMS"]) {
                entry.synonyms.push_back(synonym);
            }

            dictionary[it.key()] = entry;
        }
        file.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo " << filename << std::endl;
    }

    return dictionary;
}

int main() {
    std::string filename = "dictionary.json";
    std::map<std::string, DictionaryEntry> dictionary = load_dictionary(filename);
    int opt = menu();
    std::cout <<opt <<std::endl;
    std::string target = "A";
    std::string result = binary_search(dictionary, target);

    std::cout << "Resultado da busca para '" << target << "':\n" << result << std::endl;

    return 0;
}
