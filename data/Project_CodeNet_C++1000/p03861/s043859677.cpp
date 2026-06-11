#include <iostream>

using namespace std;

int main()
{
    long long int a, b, x;
    scanf("%lld %lld %lld", &a, &b, &x);
    long long int result;

    if(a == 0) {
        result = b / x;
        result = result + 1;
        printf("%lld\n", result);
    }

    else {
        result = b / x;
        result = result - (a - 1) / x;
        printf("%lld\n", result);
    }
}