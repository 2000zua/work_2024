#pragma once
#ifndef binary_search_algaritmo

#include <iostream>
#include <string>
#include "../headers/json.hpp"

using namespace std;
using json = nlohmann::json;

// Estrutura do nó da árvore
struct Node {
    string val;
    json meanings; 
    Node* left;
    Node* right;

    Node(const string& key, const json& mean) : val(key), meanings(mean), left(nullptr), right(nullptr) {}
};

// Classe da árvore binária de busca
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(const string& key, const json& meanings) {
        if (root == nullptr) {
            root = new Node(key, meanings);
        } else {
            _insert(root, key, meanings);
        }
    }

    bool search(const string& key) {
        int position = 1;
        Node* result = _search(root, key, position);
        if (result != nullptr) {
            std::cout << "\tMeanings:" << endl;
            for (auto& meaning : result->meanings.items()) {
                std::cout<<"\t\t"<< meaning.key() << ": " << meaning.value()[1] << endl;
            }
            std::cout << "\tPosition in tree: \n\t\t" << position << endl;
            return true;
        } else {
            std::cout << "Key don't found: " << key << endl;
            return false;
        }
    }

    void inorder() {
        _inorder(root);
    }

private:
    Node* root;

    void _insert(Node* root, const string& key, const json& meanings) {
        if (key < root->val) {
            if (root->left == nullptr) {
                root->left = new Node(key, meanings);
            } else {
                _insert(root->left, key, meanings);
            }
        } else {
            if (root->right == nullptr) {
                root->right = new Node(key, meanings);
            } else {
                _insert(root->right, key, meanings);
            }
        }
    }

    Node* _search(Node* root, const string& key, int& position) {
        if (root == nullptr || root->val == key) {
            return root;
        }
        position++;
        if (key < root->val) {
            return _search(root->left, key, position);
        } else {
            return _search(root->right, key, position);
        }
    }

    void _inorder(Node* root) {
        if (root != nullptr) {
            _inorder(root->left);
            std::cout << root->val << ": " << endl;
            for (auto& meaning : root->meanings.items()) {
                std::cout << meaning.key() << ": " << meaning.value()[1] << endl;
            }
            _inorder(root->right);
        }
    }
};

#endif