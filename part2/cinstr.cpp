#include <string>

extern std::string palavra_secreta;

bool cinstr(char chute) {
    for(char letra : palavra_secreta) {
        if(letra == chute) return true;
    }

    return false;
}