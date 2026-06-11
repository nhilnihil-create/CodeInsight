#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

#define MAX 30000

signed main() {
    int n;
    cin >> n;
    int p[n];
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    int a[n], b[n];
    rep(i, n) {
        a[i] = 1 + MAX * i;
        b[i] = 1 + MAX * (n - 1 - i);
    }
    rep(i, n) {
        a[p[i]] += i;
    }
    rep(i, n) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    rep(i, n) {
        if (i) cout << " ";
        cout << b[i];
    }
    cout << endl;
    return 0;
}