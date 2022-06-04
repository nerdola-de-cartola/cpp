#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void salvaArquivo(std::vector<std::string> palavras) {
    std::ofstream arq;
    arq.open("palavras.txt");

    if(!arq.is_open()) {
        std::cout << "Não foi possível acessar o banco de palavras" << std::endl;
        exit(1);
    }

    arq << palavras.size() << std::endl;

    for(std::string palavra : palavras) {
        arq << palavra << std::endl;
    }

    arq.close();
}