#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Welcome to my source code!

const int MOD = 1000000007;

ll p[1001];

vector<ll> prime_factor(ll n) {
    vector<ll> pf;
    double x = sqrt(n);
    for (ll i = 2; i <= x && n; i++) {
        while (n % i == 0 && n) {
            pf.push_back(i);
            n /= i;
        }
    }
    if (n != 1) pf.push_back(n);
    return pf;
}

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 2; i--) {
        vector<ll> vec = prime_factor(i);
        for (auto x : vec) p[x]++;
    }
    ll ans = 1;
    for (int i = 2; i <= n; i++) {
        if (p[i]) ans *= (p[i] + 1);
        ans %= MOD;
    }
    cout << ans << endl;
}