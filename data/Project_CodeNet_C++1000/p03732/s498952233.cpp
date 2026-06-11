#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<bool>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, W;
    cin >> N >> W;
    vector<vector<int>> vl(4);
    int w0 = -1;
    for (int i = 0; i < N; ++i) {
        int w, v;
        cin >> w >> v;
        if (i == 0)
            w0 = w;
        vl[w - w0].push_back(v);
    }

    for (int i = 0; i < 4; ++i) {
        sort(vl[i].begin(), vl[i].end());
        vl[i].push_back(0);
        reverse(vl[i].begin(), vl[i].end());
    }

    for (int i = 0; i < 4; ++i)
        for (int j = 1; j < vl[i].size(); ++j)
            vl[i][j] += vl[i][j - 1];

    int ans = 0;
    for (int i = 0; i < vl[3].size(); ++i) {
        for (int j = 0; j < vl[2].size(); ++j) {
            for (int k = 0; k < vl[1].size(); ++k) {
                ll tmp = W - ((ll)(i + j + k) * w0 + 3 * i + 2 * j + k);
                if (tmp < 0)
                    break;
                int cnt = min<ll>(tmp / w0, vl[0].size() - 1), sum = 0;
                sum += (i >= 0 ? vl[3][i] : 0);
                sum += (j >= 0 ? vl[2][j] : 0);
                sum += (k >= 0 ? vl[1][k] : 0);
                sum += (cnt >= 0 ? vl[0][cnt] : 0);
                ans = max(ans, sum);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
