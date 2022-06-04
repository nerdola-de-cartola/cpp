#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> carregaPalavras(void) {
    std::vector<std::string> palavras;
    std::string input;
    std::ifstream arq;
    int qtd_palavras;

    arq.open("palavras.txt");

    if(!arq.is_open()) {
        std::cout << "Não foi possível acessar o banco de palavras" << std::endl;
        exit(1);
    }

    arq >> qtd_palavras;
    
    for(int i = 0; i < qtd_palavras; i++) {
        arq >> input;
        palavras.push_back(input);
    }

    arq.close();

    return palavras;
}