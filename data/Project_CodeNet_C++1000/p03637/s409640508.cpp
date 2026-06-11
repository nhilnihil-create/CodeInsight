#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
    ll n; cin >> n;
    ll odd = 0, mod4 = 0;
    rep(i, n) {
        ll a; cin >> a;
        if (a%2) odd++;
        if (a%4 == 0) mod4++;
    }
    if (odd-1 < mod4) cout << "Yes" << endl;
    else if (odd-1==mod4 && n==odd+mod4) cout << "Yes" << endl;
    else cout << "No" << endl;
}