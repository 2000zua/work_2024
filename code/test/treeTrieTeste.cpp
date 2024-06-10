#pragma once
#ifndef hash_dicionario_teste

#include <chrono>
#include "../headers/json.hpp"
#include "../common/load_file.cpp"
#include "../class/treeTreiCode.cpp"

// file with 1526 line and size 1MB
void testeApp3Size_1MB(){
    Trie trie =  Trie();
    string filename = "data/DG.json"; 
    cout << "TESTE WITH 60.000 LINE"<<endl;

    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    try {
        loadWordsFromJsonApp3(filename, trie);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for load the data and insert in the struture: " << duration.count()<< " microseconds.\n" << endl;
    
    cout << "Busca por 'G': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    trie.displayMeanings("G");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for search the start in the tree: " << duration.count()<< " microseconds.\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'GLARE': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    trie.displayMeanings("GLARE");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for search the center in the tree: " << duration.count()<< " microseconds.\n" << endl;
    cout << endl;

    cout << "Busca por 'GUZZLER': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    trie.displayMeanings("GUZZLER");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;

}

// file with 15921 line and size 300KB
void testeApp3Size_4MB(){
    Trie trie =  Trie();
    string filename = "data/DS.json"; 
    cout << "TESTE WITH 200.000 LINE"<<endl;

    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    loadWordsFromJsonApp3(filename, trie);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for load the data and insert in the struture: " << duration.count()<< " microseconds.\n" << endl;
    
    cout << "Busca por 'SAARINEN': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    trie.displayMeanings("SAARINEN");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for search the start in the tree: " << duration.count()<< " microseconds.\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'SIT': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    trie.displayMeanings("SIT");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for search the center in the tree: " << duration.count()<< " microseconds.\n" << endl;
    cout << endl;


    cout << "Busca por 'SZILARD': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    trie.displayMeanings("SZILARD");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;
}

// file with 2.000.000 line and size 40MB
void testeApp3Size_40MB(){
    Trie trie =  Trie();
    string filename = "data/data.json"; 

    cout << "TESTE WITH 2.000.000 LINE"<<endl;

    auto start = std::chrono::high_resolution_clock::now();
    // Carregando palavras do arquivo e inserindo na árvore
    loadWordsFromJsonApp3(filename, trie);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for load the data and insert in the struture: " << duration.count()<< " microseconds.\n" << endl;
    
    cout << "Busca por 'AFFECTION': in  the start of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    trie.displayMeanings("AFFECTION");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for search the start in the tree: " << duration.count()<< " microseconds.\n" << endl;
    cout << endl;

    // Buscando palavras no dicionário
    cout << "Busca por 'FLAKE': in the center of tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    trie.displayMeanings("FLAKE");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n-> Time execution for search the center in the tree: " << duration.count()<< " microseconds.\n" << endl;
    cout << endl;

    cout << "Busca por 'ZWINGLI': in the and the tree" << endl;
    start = std::chrono::high_resolution_clock::now();
    trie.displayMeanings("ZWINGLI");
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "\n -> Time execution for search the and in the tree: " << duration.max << " microseconds.\n" << endl;
    cout << endl;
}

#endif

2.1.4 - Factors Affecting Time Complexity
 3.1 - Tree Trie
3.1.1 - History
3.1.3 - Time Complexity of Trie Operations
3.1.3.1 - Вставка :
3.1.3.2 - Поиск :
3.1.3.3 - Удаление :
3.1.3.1 - Поиск по префиксу:
3.1.4 - Пространственная сложност
2 - Главе № 2
2.1 - Implementation Binary Search Tree
2.1.1 - Implementation Test Binary Search Tree and result
2.2 - Implementation Hash Table
2.2.1 - Implementation Test Hash Table and result
2.3 - Implementation Tree Trie
2.3.1 - Implementation Test Tree Trie
Заключение
Приложение
Библиография



