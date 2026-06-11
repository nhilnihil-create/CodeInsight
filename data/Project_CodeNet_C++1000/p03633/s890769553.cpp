#include<iostream>
using namespace std;

typedef long long ll;

ll gcd (ll a, ll b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n;
    scanf("%d", &n);
    ll t[n];

    for (int i = 0; i < n; i++) {
        scanf("%lld", &t[i]);
    }

    ll ans = t[0];
    for (int i = 1; i < n; i++) {
        ans = lcm(ans, t[i]);
    }

    printf("%lld\n", ans);
}