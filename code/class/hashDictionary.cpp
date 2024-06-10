#pragma once
#ifndef algaritmo_hash_table_My

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <unordered_map>
#include "../headers/json.hpp"
#include <stdexcept>

using json = nlohmann::json;
using namespace std;


class HashDictionary {
private:
    int numBuckets;
    std::vector<std::list<std::pair<std::string, std::unordered_map<std::string, nlohmann::json>>>> table;

    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % numBuckets;
    }

public:
    HashDictionary(int size) {
        numBuckets = size;
        table.resize(numBuckets);
    }

    void insert(const std::string& key, const std::unordered_map<std::string, nlohmann::json>& value) {
        int index = hashFunction(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    void printMeanings(const nlohmann::json& meanings) {
        for (auto& [key, value] : meanings.items()) {
            std::cout << "Meaning ID: " << key << std::endl;
            std::cout << "\tPart of Speech: " << value[0] << std::endl;
            std::cout << "\tDefinition: " << value[1] << std::endl;
            std::cout << "\tExamples: " << std::endl;
            for (const auto& example : value[2]) {
                std::cout << "\t\t - " << example << std::endl;
            }
            std::cout << "Additional Notes: " << std::endl;
            for (const auto& note : value[3]) {
                std::cout << "\t\t - " << note <<std::endl;
            }
            cout <<"\n";
        }
    }

    std::unordered_map<std::string, nlohmann::json> search(const std::string& key) {
        int index = hashFunction(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        throw std::runtime_error("Key dont't found");
    }

};

#endif