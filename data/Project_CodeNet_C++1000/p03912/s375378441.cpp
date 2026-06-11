/*
*
*   解説見てないお
*
*/
#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

int main() {
    int n, m; cin >> n >> m;
    vector<int> x(n),y(m,0),z(100001,0);
    REP(i, n) {
        scanf("%d", &x[i]);
        y[x[i] % m]++;
        z[x[i]]++;
    }
    ll ans = 0;
    REP(i, m/2 + 1) {
        if (i == m - i || i == 0) {
            ans += y[i] / 2;
            y[i] %= 2;
        }
        else {
            int a = min(y[i], y[m - i]);
            ans += a;
            y[i] -= a;
            y[m - i] -= a;
        }
    }
    REP(i, 100001) {
        if (z[i] > 1 && y[i % m]) {
            int a = min(z[i] / 2, y[i % m] / 2);
            y[i % m] -= a * 2;
            ans += a;
        }
    }
    cout << ans << endl;
    return 0;
}