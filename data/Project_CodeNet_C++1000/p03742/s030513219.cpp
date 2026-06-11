#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

int main() {
    LL X, Y;
    scanf("%lld %lld", &X, &Y);
    if (abs(X - Y) < 2) puts("Brown");
    else puts("Alice");
    return 0;
}