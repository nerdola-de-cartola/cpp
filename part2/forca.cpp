#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "imprimeCabecalho.hpp"
#include "sorteiaPalavra.hpp"
#include "ganhou.hpp"
#include "enforcou.hpp"
#include "imprimeAcertos.hpp"
#include "imprimeErros.hpp"
#include "chute.hpp"
#include "adicionaPalavra.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> ACERTOS;
vector<char> ERROS;

int main(void) {
    imprimeCabecalho();

    palavra_secreta = sorteiaPalavra();
   
    while(!ganhou() && !enforcou()) {
        imprimeAcertos();
        imprimeErros();
        chute();
    }

    if(enforcou()) {
        cout << "Que pena, você se enforcou" << endl;
        cout << "A palavra secreta era... " << palavra_secreta << endl;
    } else {
        imprimeAcertos();
        cout << "Parabéns você venceu!" << endl;
        cout << "Deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if(resposta == 'S') {
            adicionaPalavra();
        }
    }

    return 0;
}