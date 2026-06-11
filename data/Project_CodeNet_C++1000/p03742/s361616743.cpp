#include<bits/stdc++.h>
using namespace std;

int main() {
    long long X, Y;
    scanf("%lld %lld", &X, &Y);
    if (abs(X - Y) < 2) printf("Brown");
    else printf("Alice");
    return 0;
}