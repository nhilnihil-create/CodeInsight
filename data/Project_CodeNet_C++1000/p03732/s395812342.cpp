#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> val[4];
    ll w0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            int v;
            cin >> w0 >> v;
            val[0].push_back(v);
        } else {
            int w, v;
            cin >> w >> v;
            val[w - w0].push_back(v);
        }
    }

    for (int i = 0; i < 4; i++) {
        sort(val[i].rbegin(), val[i].rend());
    }

    ll sum[4][101];
    for (int i = 0; i < 4; i++) {
        sum[i][0] = 0;
        for (int j = 1; j <= val[i].size(); j++) {
            sum[i][j] = sum[i][j - 1] + val[i].at(j - 1);
        }
    }

    ll ans = 0;
    for (int i = 0; i <= val[0].size(); i++) {
        for (int j = 0; j <= val[1].size(); j++) {
            for (int k = 0; k <= val[2].size(); k++) {
                for (int l = 0; l <= val[3].size(); l++) {
                    if (w0 * i + (w0 + 1) * j + (w0 + 2) * k + (w0 + 3) * l <= W) {
                        ans = max(ans, sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l]);
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}