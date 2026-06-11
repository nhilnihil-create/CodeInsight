#include <iostream>

int main() {
    int a, b;
    char op;

    std::cin >> a >> op >> b;
    
    if (op == '+')
        std::cout << a + b << std::endl;
    else
        std::cout << a - b << std::endl;
    
    return 0;
}