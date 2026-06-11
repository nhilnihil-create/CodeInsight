#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
const ll MAXN = 1000010;

ll N, X, ans;

ll gcd(ll, ll);

int main() {
    scanf("%lld%lld", &N, &X); 
    ll ans = gcd(min(X, N-X), max(X, N-X)) + N;
    printf("%lld\n", ans);
    return 0;
}

ll gcd(ll x, ll n) {
    if (x == 0) return -n;
    ll tem = n / x;
    ll ret = tem * 2 * x;
    return gcd(n % x, x) + ret;
}