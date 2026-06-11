#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, x, ans;

void gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (!b) return ;
    // printf("%lld %lld\n", a, b);
    ans += 2 * (a / b) * b;
    if (a % b == 0) ans -= b;
    gcd(b, a % b);
}

int main() {
    cin >> n >> x;
    ans = n;
    gcd(n - x, x);
    cout << ans << endl;
    return 0;
}