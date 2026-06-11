#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL X, Y;

int main(){
    scanf("%lld %lld", &X, &Y);
    if (abs(X-Y) > 1) puts("Alice");
    else puts("Brown");
    return 0;
}
