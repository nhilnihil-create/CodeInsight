#include <iostream>

int main() {
    std::string N; std::cin >> N;

    std::cout << ((N[0] == '9' || N[1] == '9')?("Yes"):("No")) << std::endl;
    return 0;
}