#include <iostream>

int main()
{
    int dest;
    int steps = 1, current = 0;
    std::cin >> dest;
    for(;; steps++) {
        current += steps;
        if(current >= dest)
            break;
    }
    
    std::cout << steps;

    return 0;
}