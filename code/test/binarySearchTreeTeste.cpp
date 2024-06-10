#pragma once
#ifndef binary_search_teste

#include <chrono>
#include "../headers/json.hpp"
#include "../class/binarySearchTree.cpp"
#include "../common/load_file.cpp"

// file with 1526 line and size 30KB
void testeAppSize_30kB(){
    BinarySearchTree bst;
    string filename = "data/DX.json"; 
    cout << "TESTE WITH 1526 LINE"<<endl;

    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    loadWordsFromJsonApp1(filename, bst);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n\nTempo de execução for load the data and insert in the struture: " << duration.count()<< " microseconds.\n\n" << endl;
    
    
    cout << "Busca por 'X': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("X");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the start in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'XYRIDACEAE': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("XYRIDACEAE");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the center in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;


    cout << "Busca por 'XX': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("XX");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;

}

// file with 15921 line and size 300KB
void testeAppSize_300kB(){
    BinarySearchTree bst;
    string filename = "data/DJ.json"; 

    cout << "\n\nTESTE WITH 15921 LINE"<<endl;
    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    loadWordsFromJsonApp1(filename, bst);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\nTempo de execução for load the data and insert in the struture: " << duration.count()<< " microseconds.\n\n" << endl;
    
    
    cout << "Busca por 'J': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("J");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the start in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'JITTER': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("JITTER");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the center in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;


    cout << "Busca por 'JUXTAPOSITION': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("JUXTAPOSITION");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;
}

// file with 63349 line and size 1MG
void testeAppSize_1MB(){
    BinarySearchTree bst;
    string filename = "data/DL.json"; 

    cout << "\n\nTESTE WITH 63349 LINE"<<endl;
    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    loadWordsFromJsonApp1(filename, bst);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\nTempo de execução for load the data and insert in the struture: " << duration.count()<< " microseconds.\n\n" << endl;
    
    
    cout << "Busca por 'LABEL': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("LABEL");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the start in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'LIP': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("LIP");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the center in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;


    cout << "Busca por 'LWEI': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("LWEI");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;
}

// file with 150000 line and size 5MB
void testeAppSize_5MB(){
    BinarySearchTree bst;
    string filename = "data/DP.json"; 

    cout << "\n\nTESTE WITH 150000 LINE"<<endl;
    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    loadWordsFromJsonApp1(filename, bst);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\nTempo de execução for load the data and insert in the struture: " << duration.count()<< " microseconds.\n\n" << endl;
    
    cout << "Busca por 'PACE': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("PACE");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the start in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'PLAYER': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("PLAYER");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the center in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;

    cout << "Busca por 'PINER': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("PINER");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;
}

// file with 1526 line and size 40MB
void testeAppSize_40MB(){
    BinarySearchTree bst;
    string filename = "data/Data.json"; 

    cout << "\n\nTESTE WITH 2000000 LINE"<<endl;
    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    loadWordsFromJsonApp1(filename, bst);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\nTempo de execução for load the data and insert in the struture: " << duration.count()<< " microseconds.\n\n" << endl;
    
    cout << "Busca por 'AARON': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("AARON");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the start in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'LIMITATION': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("LIMITATION");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the center in the tree: " << duration.count()<< " microseconds.\n\n" << endl;
    cout << endl;

    cout << "Busca por 'PINER': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    bst.search("ZWORYKIN");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Tempo de execução for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;
}

#endif