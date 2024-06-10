#pragma once
#ifndef algaritmo_tree_Trei

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "../headers/json.hpp" 

using json = nlohmann::json;

// Classe TrieNode
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    json meanings; // Armazena significados associados ao final da palavra

    TrieNode() : isEndOfWord(false) {}
};

// Classe Trie
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Função para inserir uma palavra na Trie e associar significados
    void insert(const std::string& word, const json& meanings) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
        currentNode->meanings = meanings;
    }

    // Função para pesquisar uma palavra na Trie e retornar o nó correspondente
    TrieNode* searchNode(const std::string& word) const {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return nullptr;
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord ? currentNode : nullptr;
    }

    // Função para exibir os significados de uma palavra
    void displayMeanings(const std::string& word) const {
        TrieNode* node = searchNode(word);
        if (node) {
            std::cout << "Meanings of '" << word << "':\n";
            for (const auto& [key, meaning] : node->meanings.items()) {
                std::cout << "Meaning " << key << ":\n";
                std::cout << "  Type: " << meaning[0] << "\n";
                std::cout << "  Definition: " << meaning[1] << "\n";
                std::cout << "  Synonyms: ";
                if (meaning[2].empty()) {
                    std::cout << "None";
                } else {
                    for (const auto& synonym : meaning[2]) {
                        std::cout << synonym << " ";
                    }
                }
                std::cout << "\n  Examples: ";
                if (meaning[3].empty()) {
                    std::cout << "None";
                } else {
                    for (const auto& example : meaning[3]) {
                        std::cout << example << " ";
                    }
                }
                std::cout << "\n";
            }
        } else {
            std::cout << "No meanings found for '" << word << "'\n";
        }
    }

    // Destrutor para desalocar memória
    ~Trie() {
        deleteTrie(root);
    }

private:
    void deleteTrie(TrieNode* node) {
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }
};


#endif