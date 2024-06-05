// // #include <iostream>
// // #include <map>
// // #include <string>

// // using namespace std;

// // string binary_search(const std::map<std::string, std::string>& dictionary, const std::string& target){
// //     auto left = dictionary.begin();
// //     auto right = --dictionary.end();

// //     while (distance(left, right) >= 0) {
// //         auto mid = left;
// //         advance(mid, distance(left, right) / 2);

// //         if (mid->first == target) {
// //             return mid->second;
// //         } else if (mid->first < target) {
// //             left = ++mid;
// //         } else {
// //             right = --mid;
// //         }
// //     }

// //     return "Not Found";  //
// // }


// // int main(){
// //     std::map<std::string, std::string> dictionary = {
// //         {"apple", "A fruit that is red, green, or yellow."},
// //         {"banana", "A long yellow fruit."},
// //         {"cherry", "A small, round fruit that is typically red or black."},
// //         {"date", "A sweet fruit from the date palm tree."},
// //         {"fig", "A fruit with a soft skin and many seeds inside."},
// //         {"grape", "A small, round fruit used to make wine."}
// //     };
// //     std::string target = "cherry";
// //     std::string result = binary_search(dictionary, target);

// //     std::cout << "Resultado da busca para '" << target << "': " << result << std::endl;

// //     return 0;
// // }

// #include <iostream>
// #include <fstream>
// #include <map>
// #include <string>

// // Função de busca binária em um dicionário ordenado
// std::string binary_search(const std::map<std::string, std::string>& dictionary, const std::string& target) {
//     auto left = dictionary.begin();
//     auto right = --dictionary.end();

//     while (std::distance(left, right) >= 0) {
//         auto mid = left;
//         std::advance(mid, std::distance(left, right) / 2);

//         if (mid->first == target) {
//             return mid->second;
//         } else if (mid->first < target) {
//             left = ++mid;
//         } else {
//             right = --mid;
//         }
//     }

//     return "Not Found";  // Retorna "Not Found" se a chave não for encontrada
// }

// // Função para carregar o dicionário a partir de um arquivo de texto
// std::map<std::string, std::string> load_dictionary(const std::string& filename) {
//     std::map<std::string, std::string> dictionary;
//     std::ifstream file(filename);
//     std::string key, value;

//     if (file.is_open()) {
//         while (getline(file, key) && getline(file, value)) {
//             dictionary[key] = value;
//             std::cout << key << "=> "<< value <<"\n"<<std::endl;
//         }
//         file.close();
//     } else {
//         std::cerr << "Não foi possível abrir o arquivo " << filename << std::endl;
//     }

//     return dictionary;
// }

// int main() {
//     std::string filename = "dictionary.txt";
//     std::map<std::string, std::string> dictionary = load_dictionary(filename);

//     std::string target = "apple";
//     std::string result = binary_search(dictionary, target);

//     std::cout << "Resultado da busca para '" << target << "': " << result << std::endl;

//     return 0;
// }


// #include <iostream>
// #include <fstream>
// #include <json/json.h>
// 
// int main()
// {
//     Json::Value people;
//     std::ifstream people_file("people.json", std::ifstream::binary);
//     people_file >> people;
// 
//     std::cout << people["Anna"] << "\n";
//     std::cout << people["Anna"]["profession"] << "\n";
// }
