#include <vector>

extern std::vector<char> ERROS;

bool enforcou(void) {
    if(ERROS.size() >= 5) return true;
    return false;
}