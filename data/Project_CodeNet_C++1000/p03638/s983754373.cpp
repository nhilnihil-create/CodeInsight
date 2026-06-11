#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> ans(h, vector<int>(w));
    int idx = 0;
    rep(i, h) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; ++j) {
                ans[i][j] = idx;
                a[idx]--;

                if (a[idx] == 0)
                    ++idx;
            }
        } else {
            for (int j = w - 1; j >= 0; --j) {
                ans[i][j] = idx;
                a[idx]--;

                if (a[idx] == 0)
                    ++idx;
            }
        }
    }

    rep(i, h) {
        rep(j, w) {
            if (j != 0)
                cout << " ";
            cout << ans[i][j] + 1;
        }
        cout << endl;
    }

    return 0;
}