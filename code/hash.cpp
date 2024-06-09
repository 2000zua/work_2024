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

int main() {
    testeApp2Size_1MB();

    return 0;
}
