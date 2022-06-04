#include <iostream>
#include <vector>
#include <string>
#include <map>

extern std::string palavra_secreta;
extern std::map<char, bool> ACERTOS;

void imprimeAcertos(void) {
    for(char letra : palavra_secreta) {
        if(ACERTOS[letra]) {
            std::cout << letra << " ";
        } else {
            std::cout << "_ ";
        }
    }

    std::cout << std::endl;
}