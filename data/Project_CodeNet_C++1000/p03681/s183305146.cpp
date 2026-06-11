#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)
#define MX 1e5

const int mod = 1e9 + 7;
ll f(ll x) {
    ll a = 1;
    for (int i = 2; i <= x; i++) {
        a = a * i % mod;
    }
    return a;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    if (abs(a-b)>1) {
        cout << 0 << "\n";
    } else if (a == b) {
        cout << f(a)*f(b)%mod * 2%mod << "\n";
    } else if (a != b) {
        cout << f(a) * f(b)%mod<< "\n";
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i = 1;
    //cin >> t;
    while(t--) {
        //cout << "Case #" << i << ": ";
        solve();
        //i++;
    }
    return 0;
}
