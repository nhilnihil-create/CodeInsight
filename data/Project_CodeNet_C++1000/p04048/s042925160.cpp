//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;


int main() {
    // freopen("in.txt", "r", stdin);
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long v = __gcd(n, k);
    n /= v;
    k /= v;
    long long ans = 1 + (n - 1) + 1 + (2 * (n - 2));
    printf("%lld\n", ans * v);
}