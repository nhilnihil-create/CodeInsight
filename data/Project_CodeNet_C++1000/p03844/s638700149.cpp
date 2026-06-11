#include <stdio.h>
#include <iostream>

int main()
{
    int n1, n2;
    char op;
    std::cin >> n1>>op>>n2;
    if(op == '-'){
        std::cout << n1 - n2 << std::endl;
    }
    if(op == '+'){
        std::cout << n1 + n2 << std::endl;
    }
    

    return 0;
}