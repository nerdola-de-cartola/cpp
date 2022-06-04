#include <iostream>
#include <string>
#include "carregaPalavras.hpp"
#include "salvaArquivo.hpp"

void adicionaPalavra(void) {
    std::cout << "Digite a nova palavra usando somente letras maiúsculas" << std::endl;
    std::string nova_palavra;
    std::cin >> nova_palavra;
    std::vector<std::string> palavras = carregaPalavras();
    palavras.push_back(nova_palavra);
    salvaArquivo(palavras);
}