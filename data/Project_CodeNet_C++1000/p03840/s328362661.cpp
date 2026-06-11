#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d, e, f, g;

int main() {
    scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &g);
    long long ans1 = 0, ans2 = 0;
    ans1 += d / 2 * 2 + e / 2 * 2;
    ans1 += a / 2 * 2;
    ans1 += min({a % 2, d % 2, e % 2}) * 3;
    ans2 = 3 + (d - 1) / 2 * 2 + (e - 1) / 2 * 2;
    ans2 += (a - 1) / 2 * 2;
    if (!a || !d || !e) ans2 = 0;
    printf("%lld\n", max(ans1, ans2) + b);
    return 0;
}