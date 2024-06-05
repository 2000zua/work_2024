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

// Função para formatar o resultado da busca
std::string format_result(const DictionaryEntry& entry) {
    std::string result = "MEANINGS:\n";
    for (const auto& meaning : entry.meanings) {
        result += std::to_string(meaning.first) + ": ";
        for (const auto& item : meaning.second) {
            result += item + ", ";
        }
        result.pop_back();
        result.pop_back();
        result += "\n";
    }

    result += "SYNONYMS: ";
    for (const auto& synonym : entry.synonyms) {
        result += synonym + ", ";
    }
    result.pop_back();
    result.pop_back();
    result += "\n";

    return result;
}

// Função de busca ternária em um dicionário ordenado
std::string ternary_search(const std::map<std::string, DictionaryEntry>& dictionary, const std::string& target) {
    auto left = dictionary.begin();
    auto right = --dictionary.end();

    while (left != dictionary.end() && std::distance(left, right) >= 0) {
        auto one_third = left;
        auto two_third = left;
        std::advance(one_third, std::distance(left, right) / 3);
        std::advance(two_third, 2 * std::distance(left, right) / 3);

        if (one_third->first == target) {
            return format_result(one_third->second);
        } else if (two_third->first == target) {
            return format_result(two_third->second);
        }

        if (target < one_third->first) {
            right = --one_third;
        } else if (target > two_third->first) {
            left = ++two_third;
        } else {
            left = ++one_third;
            right = --two_third;
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

    std::string target = "A";
    std::string result = ternary_search(dictionary, target);

    std::cout << "Resultado da busca para '" << target << "':\n" << result << std::endl;

    return 0;
}
