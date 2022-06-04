#include <vector>
#include <string>
#include <map>

extern std::string palavra_secreta;
extern std::map<char, bool> ACERTOS;

bool ganhou(void) {
    for(char letra : palavra_secreta) {
        if(!ACERTOS[letra]) return false;
    }

    return true;
}