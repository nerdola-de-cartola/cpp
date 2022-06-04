#include <iostream>
#include <map>
#include <vector>
#include "cinstr.hpp"

extern std::map<char, bool> ACERTOS;
extern std::vector<char> ERROS;

void chute(void) {
    char chute;
    std::cout << "Seu chute: ";
    std::cin >> chute;

    if(cinstr(chute)) {
        std::cout << "Acertou" << std::endl;
        ACERTOS[chute] = true;
    } else {
        std::cout << "Errou" << std::endl;
        ERROS.push_back(chute);
    }
}