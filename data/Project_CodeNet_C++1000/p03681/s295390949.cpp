#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    ll ans = 1;
    ll diff = abs(n - m);
    if (diff > 1) ans = 0;
    else {
        if (diff == 0) {
            REP(i, n) {
                ans *= (i + 1);
                ans %= mod;
            }
            REP(i, m) {
                ans *= (i + 1);
                ans %= mod;
            }
            ans *= 2;
            ans %= mod;
        }
        if (diff == 1) {
            REP(i, n) {
                ans *= (i + 1);
                ans %= mod;
            }
            REP(i, m) {
                ans *= (i + 1);
                ans %= mod;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
