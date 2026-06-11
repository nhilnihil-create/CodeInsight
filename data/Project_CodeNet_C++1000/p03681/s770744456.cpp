#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const int MOD = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    if(abs(n - m) >= 2) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    if(abs(n - m) == 1) {
        repl(i, 1, n + 1) {
            ans *= i;
            ans %= MOD;
        }
        repl(i, 1, m + 1) {
            ans *= i;
            ans %= MOD;
        }
    }
    else {
        repl(i, 1, n + 1) {
            ans *= i;
            ans %= MOD;
        }
        repl(i, 1, m + 1) {
            ans *= i;
            ans %= MOD;
        }
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
