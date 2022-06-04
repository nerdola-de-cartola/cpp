#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> ACERTOS;
vector<char> ERROS;

bool cinstr(char chute) {
    for(char letra : palavra_secreta) {
        if(letra == chute) return true;
    }

    return false;
}

bool ganhou(void) {
    for(char letra : palavra_secreta) {
        if(!ACERTOS[letra]) return false;
    }

    return true;
}

bool enforcou(void) {
    if(ERROS.size() >= 5) return true;
    return false;
}

void chute(void) {
    char chute;
    cout << "Seu chute: ";
    cin >> chute;

    if(cinstr(chute)) {
        cout << "Acertou" << endl;
        ACERTOS[chute] = true;
    } else {
        cout << "Errou" << endl;
        ERROS.push_back(chute);
    }
}

void imprimeAcertos(void) {
    for(char letra : palavra_secreta) {
        if(ACERTOS[letra]) {
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }

    cout << endl;
}

void imprimeErros(void) {
    cout << "Chutes errados: ";
    for(char letra : ERROS) {
        cout << letra << " ";
    }

    cout << endl;
}

vector<string> carregaPalavras(void) {
    vector<string> palavras;
    string input;
    ifstream arq;
    int qtd_palavras;

    arq.open("palavras.txt");

    if(!arq.is_open()) {
        cout << "Não foi possível acessar o banco de palavras" << endl;
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

void imprimeCabecalho(void) {
    cout << "***********************" << endl;
    cout << "**** JOGO DA FORCA ****" << endl;
    cout << "***********************" << endl;
}

string sorteiaPalavra(void) {
    srand(time(NULL));
    vector<string> palavras = carregaPalavras();
    int i = rand() % palavras.size();

    return palavras[i];
}

void salvaArquivo(vector<string> palavras) {
    ofstream arq;
    arq.open("palavras.txt");

    if(!arq.is_open()) {
        cout << "Não foi possível acessar o banco de palavras" << endl;
        exit(1);
    }

    arq << palavras.size() << endl;

    for(string palavra : palavras) {
        arq << palavra << endl;
    }

    arq.close();
}

void adicionaPalavra(void) {
    cout << "Digite a nova palavra usando somente letras maiúsculas" << endl;
    string nova_palavra;
    cin >> nova_palavra;
    vector<string> palavras = carregaPalavras();
    palavras.push_back(nova_palavra);
    salvaArquivo(palavras);
}

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