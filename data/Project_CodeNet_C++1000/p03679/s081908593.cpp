#include <iostream>

int main()
{
    int X, A, B;
    std::cin >> X >> A >> B;
    if (B - A <= 0)
    {
        std::cout << "delicious" << std::endl;
    }
    else if (0 < B - A && B - A <= X)
    {
        std::cout << "safe" << std::endl;
    }
    else
    {
        std::cout << "dangerous" << std::endl;
    }
    return 0;
}
