#pragma once
#ifndef hash_dicionario_teste

#include <chrono>
#include "../headers/json.hpp"
#include "../common/load_file.cpp"
#include "../class/hashDictionary.cpp"

// file with 1526 line and size 30KB
void testeApp2Size_1MB(){
    HashDictionary dict = HashDictionary();
    string filename = "data/DG.json"; 

    cout << "TESTE WITH 60.000 LINE"<<endl;

    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    loadWordsFromJsonApp2(filename, dict);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n\nTempo de execução for load the data and insert in the struture: " << duration.count()<< " microseconds.\n\n" << endl;
    
    
    cout << "Busca por 'G': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    dict.search("G");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the start in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'GLARE': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    dict.search("GLARE");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the center in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;


    cout << "Busca por 'GUZZLER': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    dict.search("GUZZLER");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;

}

// file with 15921 line and size 300KB
void testeApp2Size_4MB(){
    HashDictionary dict = HashDictionary();
    string filename = "data/DS.json"; 

    cout << "TESTE WITH 200.000 LINE"<<endl;

    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    loadWordsFromJsonApp2(filename, dict);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n\nTempo de execução for load the data and insert in the struture: " << duration.count()<< " microseconds.\n\n" << endl;
    
    
    cout << "Busca por 'SAARINEN': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    dict.search("SAARINEN");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the start in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'SIT': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    dict.search("SIT");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the center in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;


    cout << "Busca por 'SZILARD': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    dict.search("SZILARD");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;
}

// file with 1526 line and size 40MB
void testeApp2Size_40MB(){
    HashDictionary dict = HashDictionary();
    string filename = "data/data.json"; 

    cout << "TESTE WITH 2.000.000 LINE"<<endl;

    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    loadWordsFromJsonApp2(filename, dict);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n\nTempo de execução for load the data and insert in the struture: " << duration.count()<< " microseconds.\n\n" << endl;
    
    
    cout << "Busca por 'AFFECTION': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    dict.search("AFFECTION");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the start in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'FLAKE': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    dict.search("FLAKE");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the center in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;


    cout << "Busca por 'ZWINGLI': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    dict.search("ZWINGLI");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;
}

#endif