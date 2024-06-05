#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "json.hpp"

// Para conveniência
using json = nlohmann::json;

// Função de busca binária em um dicionário ordenado
std::string binary_search(const std::map<std::string, std::string>& dictionary, const std::string& target) {
    auto left = dictionary.begin();
    auto right = --dictionary.end();

    while (std::distance(left, right) >= 0) {
        auto mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        if (mid->first == target) {
            return mid->second;
        } else if (mid->first < target) {
            left = ++mid;
        } else {
            right = --mid;
        }
    }

    return "Not Found";  // Retorna "Not Found" se a chave não for encontrada
}

// Função para carregar o dicionário a partir de um arquivo JSON
std::map<std::string, std::string> load_dictionary(const std::string& filename) {
    std::map<std::string, std::string> dictionary;
    std::ifstream file(filename);
    json j;

    if (file.is_open()) {
        file >> j;
        for (json::iterator it = j.begin(); it != j.end(); ++it) {
            dictionary[it.key()] = it.value();
        }
        file.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo " << filename << std::endl;
    }

    return dictionary;
}
