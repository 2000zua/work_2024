#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <chrono>
#include "./headers/json.hpp"
#include "./class/binarySearchTree.cpp"
#include "test/binarySearchTreeTeste.cpp"

using json = nlohmann::json;
using namespace std;

void funcionalApp();

// Exemplo de uso
int main() {
    // testeAppSize_30kB();
    //testeAppSize_300kB();
    // testeAppSize_1MB();
    // testeAppSize_5MB();
    // testeAppSize_40MB();
    funcionalApp();
    return 0;
}


void funcionalApp(){
    BinarySearchTree bst = BinarySearchTree();
    string filename = ""; 
    bool run = true;
    string search_word = "";

    while (run){
        cout << "[For close the program type 0]\nType the word: ";
        cin >> search_word;
        // masiculu o meu texto
        transform(search_word.begin(), search_word.end(), search_word.begin(), ::toupper);
        
        if (search_word == "0")
        {
            run = false;
        }
        
        if (!search_word.empty()) {
            char first_char = toupper(search_word[0]);
            // Carregando palavras do arquivo e inserindo na árvore
            filename = "data/D"+string(1, first_char)+".json";
            
            // time start
            auto start = std::chrono::high_resolution_clock::now();
            loadWordsFromJsonApp1(filename, bst);
            //cout << "Busca por '"<<search_word<<"' : "<<endl;
            bst.search(search_word);
            // time out
            auto end = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            
            cout << "Tempo de execução: " << duration.count()<< " microssegundos\n\n" << endl;
        } else {
            cout << "A palavra inserida está vazia." << endl;
        }
    }
    cout << endl;
}

