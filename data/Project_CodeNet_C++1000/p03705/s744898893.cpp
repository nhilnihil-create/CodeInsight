#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll nCr(ll n, ll r) {
    ll a = 1;
    for (ll i = 1; i <= r; i++) {
       a *= n--;
       a /= i;
    }
    return a;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (a > b || (n == 1 && (b - a) > 0)) {
        cout << 0 << endl;
        return 0;
    }

    cout << (b - a) * (n - 2) + 1 << endl;
    return 0;
}