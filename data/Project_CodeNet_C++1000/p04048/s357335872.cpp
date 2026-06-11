#include <iostream>

int main()
{
    long long N, X;
    std::cin >> N >> X;

    long long L = X;
    long long a = X;
    long long b = N - X;
    while (1){
        long long r = a % b;
        L += 2 * a + b - r;
        if(r == 0){
            L -= b; std::cout << L << std::endl; return 0;
        }
        a = b - r;
        b = r;
    }
}