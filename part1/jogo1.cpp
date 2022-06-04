#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    int chute, tentativa = 1, total_tentativas;
    bool acertou = false, maior;
    double pontos = 1000, pontos_perdidos;
    char dificuldade;

    cout << "********************************" << endl;
    cout << "BEM VINDO AO JOGO DA ADIVINHAÇÃO" << endl;
    cout << "********************************" << endl;

    cout << "Escolha seu nível de dificuldade" << endl;
    cout << "Fácil (F) Médio (M) Difícil (D)" << endl;

    cin >> dificuldade;

    if(dificuldade == 'F') total_tentativas = 10;
    else if(dificuldade == 'M') total_tentativas = 8;
    else total_tentativas = 5;

    while(tentativa <= total_tentativas) {
        cout << "Tentativa " << tentativa << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        tentativa++;

        acertou = chute == NUMERO_SECRETO;
        maior = chute > NUMERO_SECRETO;
        pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos -= pontos_perdidos;

        if(acertou) {
            cout << "Parabéns você acertou o número secreto" << endl;
            break;
        } else if(maior) {
            cout << "Seu chute foi maior que o número secreto" << endl;
        } else {
            cout << "Seu chute foi menor que o número secreto" << endl;
        }
    }

    cout << "Fim de jogo!" << endl;
    if(acertou) {
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos" << endl;  
    } else {
        cout << "Você perdeu, tente novamente!" << endl;
    }

    return 0;
}
