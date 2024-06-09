#include "binary_search.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "json.hpp"


int main() {
    std::string filename = "dictionary.json";
    std::map<std::string, std::string> dictionary = load_dictionary(filename);

    std::string target = "cherry";
    std::string result = binary_search(dictionary, target);

    std::cout << "Resultado da busca para '" << target << "': " << result << std::endl;

    return 0;
}

