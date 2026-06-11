#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<ll> x(n); for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = n-1; i >= 1; i--) x[i] -= x[i-1];

    int m; ll k; cin >> m >> k;
    vector<vector<int>> p(64,vector<int>(n));
    for (int i = 0; i < n; i++) p[0][i] = i;
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        swap(p[0][a-1], p[0][a]);
    }
    for (int i = 1; i < 64; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        int s = i;
        for (int j = 63; j >= 0; j--) {
            if (k & 1ll<<j) s = p[j][s];
        }
        ans[i] = x[s];
    }
    for (int i = 0; i < n; i++) {
        if (i) ans[i] += ans[i-1];
        cout << fixed << setprecision(10) << (double)ans[i] << endl;
    }
    return 0;
}