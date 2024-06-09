#pragma once
#ifndef algaritmo_hash_table

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "../headers/json.hpp"

using json = nlohmann::json;
using namespace std;

// Classe do Dicionário usando Tabela Hash
class HashDictionary {
public:
    void insert(const string& key, const json& meanings) {
        // Inserindo a chave e seus significados na tabela hash
        hash_table[key] = meanings;
    }

    bool search(const string& key) {
        auto it = hash_table.find(key);
        if (it != hash_table.end()) {
            cout << "\tChave encontrada: " << it->first << endl;
            cout << "\tSignificados:" << endl;
            for (auto& meaning : it->second.items()) {
                cout <<"\t\t"<< meaning.key() << ": " << meaning.value()[1] << endl;
            }
            return true;
        } else {
            cout << "Chave não encontrada: " << key << endl;
            return false;
        }
    }

    void print() {
        // Imprimindo todas as chaves e seus significados na tabela hash
        for (const auto& pair : hash_table) {
            cout << pair.first << ": " << endl;
            for (auto& meaning : pair.second.items()) {
                cout << meaning.key() << ": " << meaning.value()[1] << endl;
            }
        }
        cout << endl;
    }

private:
    unordered_map<string, json> hash_table;
};

#endif