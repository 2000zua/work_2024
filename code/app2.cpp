#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "headers/json.hpp"
#include "class/hashDictionary.cpp"
#include "common/load_file.cpp"
#include "test/hashDicionarioTeste.cpp"

using json = nlohmann::json;
using namespace std;

void funcionalApp();

int main() {
    // funcionalApp();
    // testeApp2Size_1MB();
    testeApp2Size_40MB();
    return 0;
}

void funcionalApp(){
    HashDictionary dict = HashDictionary(10000000);
    string filename = "";
    string search_word = "";

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
            try
            {
                loadWordsFromJsonApp2(filename, dict);
                std::unordered_map<std::string, nlohmann::json> result = dict.search(search_word);
                dict.printMeanings(result);
                cout <<"aqui\n";
            }
            catch(const std::runtime_error& e)
            {
               std::cout << e.what() << std::endl;
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


