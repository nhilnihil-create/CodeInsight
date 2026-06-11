#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int k, s;
    cin >> k >> s;
    int ans = 0;
    rep(x, k + 1) {
        rep(y, k + 1) {
            int z = s - x - y;
            if(z >= 0 && z <= k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
