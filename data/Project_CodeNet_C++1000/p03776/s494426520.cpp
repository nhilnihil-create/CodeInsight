#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
ll C[51][51];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    rep(i, 51) rep(j, i + 1) {
        if (j == 0)
            C[i][j] = 1;
        else
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }

    int n, a, b;
    cin >> n >> a >> b;
    vector<double> vec(n);
    rep(i, n) cin >> vec[i];
    sort(vec.begin(), vec.end(), greater<double>());
    double sum = 0;
    rep(i, a) sum += vec[i];
    int p = 0, q = 0;
    rep(i, n) {
        if (vec[i] == vec[a - 1]) {
            p++;
            if (i < a) q++;
        }
    }
    ll ans = 0;
    if (vec[0] == vec[a - 1]) {
        repl(i, a, b + 1) ans += C[p][min(i, p - i)];
    } else {
        ans = C[p][min(q, p - q)];
    }
    sum /= (double)a;
    CST(10) << sum << endl;
    cout << ans << endl;
    return 0;
}