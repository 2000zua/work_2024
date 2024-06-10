#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "headers/json.hpp" 
#include "class/treeTreiCode.cpp"
#include "common/load_file.cpp"
#include "test/treeTrieTeste.cpp"

void functionalApp();

int main() {
    // functionalApp();
    // testeApp3Size_1MB();
    // testeApp3Size_4MB();
    testeApp3Size_40MB();
    // functionalApp();
    return 0;
}

void functionalApp(){
    Trie trie;
    string filename;
    std::string search_word;

    while (true){
        cout << "[For close the program type .exit]\nType the word: ";
        cin >> search_word;
        // masiculu o meu texto
        transform(search_word.begin(), search_word.end(), search_word.begin(), ::toupper);
        
        if (search_word == ".EXIT"){
            break;
        }
        
        if (!search_word.empty()) {
            char first_char = toupper(search_word[0]);
            // Carregando palavras do arquivo e inserindo na árvore
            filename = "data/D"+string(1, first_char)+".json";
            
            // time start
            auto start = std::chrono::high_resolution_clock::now();
            try {
                loadWordsFromJsonApp3(filename, trie);
                trie.displayMeanings(search_word);
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            
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


