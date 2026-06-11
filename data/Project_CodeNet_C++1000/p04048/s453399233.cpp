#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans(ll n, ll x) { return x ? (ans(x, n % x) + n / x * x * 2) : -n; }
ll x, n;
int main() {
    scanf("%lld%lld", &n, &x);
    if (n < x + x) x = n - x;
    printf("%lld\n", n + ans(n - x, x));
    return 0;
}