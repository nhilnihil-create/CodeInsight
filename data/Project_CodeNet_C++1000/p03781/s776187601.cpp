#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    long long X;
    long long ans = 0;
    // freopen("in.in", "r", stdin);
    scanf("%lld", &X);
    while (ans * (ans + 1) < 2 * X) {
        ++ans;
    }
    printf("%lld", ans);
}
