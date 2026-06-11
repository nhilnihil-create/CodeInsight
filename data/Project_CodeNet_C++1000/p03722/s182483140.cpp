#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 998244353
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> d(n, vector<ll>(n, LLONG_MAX / 2000));
    for(int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = -c;
    }
    for(int i = 0; i < n; i++) {         // 経由する頂点
        for(int j = 0; j < n; j++) {     // 開始頂点
            for(int k = 0; k < n; k++) { // 終端
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    if(d[0][0] == 0) {
        cout << -d[0][n - 1] << endl;
    } else {
        cout << "inf" << endl;
    }
}