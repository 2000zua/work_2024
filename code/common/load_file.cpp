#pragma once
#ifndef load_file_json

#include <fstream>
#include "../headers/json.hpp"
#include "../class/binarySearchTree.cpp"
#include "../class/hashDictionary.cpp"

// Função para carregar palavras de um arquivo JSON
void loadWordsFromJsonApp1(const string& filename, BinarySearchTree& structure) {
    ifstream file(filename, ifstream::in | ifstream::binary);
    if (!file.is_open()) {
        cerr << "Não foi possível abrir o arquivo " << filename << endl;
        return;
    }

    // Melhorar a leitura com buffer para grandes arquivos
    const size_t bufferSize = 50024*1024;  // 50MB buffer
    file.rdbuf()->pubsetbuf(new char[bufferSize], bufferSize);

    json j;
    file >> j;

    for (auto& element : j.items()) {
        structure.insert(element.key(), element.value()["MEANINGS"]);
    }
}

void loadWordsFromJsonApp2(const string& filename, HashDictionary& dict) {
    ifstream file(filename, ifstream::in | ifstream::binary);
    if (!file.is_open()) {
        cerr << "Não foi possível abrir o arquivo " << filename << endl;
        return;
    }

    // Usar buffer grande para melhorar a leitura
    const size_t bufferSize = 50024*1024;  // 50KB buffer
    file.rdbuf()->pubsetbuf(new char[bufferSize], bufferSize);

    json j;
    file >> j;

    for (auto& element : j.items()) {
        dict.insert(element.key(), element.value()["MEANINGS"]);
    }
}

#endif