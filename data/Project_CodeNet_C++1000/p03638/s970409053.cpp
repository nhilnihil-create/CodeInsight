#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vector<vector<int>> ans(H, vector<int>(W));

    int cnt = 0;
    int a_i = 0;
    rep(i, H) {
        rep(j, W) {
            int nj = j;
            if (i % 2) nj = W - 1 - j;
            ans[i][nj] = a_i + 1;
            cnt++;

            if (cnt == a[a_i]) {
                a_i++;
                cnt = 0;
            }
        }
    }

    rep(i, H) {
        rep(j, W) {
            cout << ans[i][j];
            if (j != W - 1) cout << " ";
        }
        cout << endl;
    }
}