#pragma once
#ifndef binary_search

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "json.hpp"
#include "binary_search.cpp"


std::string binary_search(const std::map<std::string, std::string>& dictionary, const std::string& target);
std::map<std::string, std::string> load_dictionary(const std::string& filename);


#endif