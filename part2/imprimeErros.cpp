#include <iostream>
#include <vector>

extern std::vector<char> ERROS;

void imprimeErros(void) {
    std::cout << "Chutes errados: ";
    for(char letra : ERROS) {
        std::cout << letra << " ";
    }

    std::cout << std::endl;
}