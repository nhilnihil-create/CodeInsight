#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define loop(i, a, b) for (int i = a; i < (int)(b); i++)

struct Item {
    ll weight;
    ll value;
};

const int WIDTH = 310;
ll N, W, OFFSET;
vector<Item> items;
ll dp[101][101][WIDTH];

int main() {
    cin >> N >> W;
    rep (i, N) {
        ll w, v;
        cin >> w >> v;
        if (i == 0) {
            OFFSET = w;
        }
        w -= OFFSET;
        items.push_back({w, v});
    }
    rep(i, 101) rep(j, 101) rep(k, WIDTH) dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    ll ans = 0;
    rep(i, N) {
        rep(j, N) {
            rep(k, WIDTH) {
                if (dp[i][j][k] < 0) {
                    continue;
                }
                dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
                //
                int k2 = k + items[j].weight;
                ll w = (i + 1) * OFFSET + k2;
                if (w > W) {
                    continue;
                }
                ll nextV = dp[i][j][k] + items[j].value;
                nextV = max(dp[i + 1][j + 1][k2], nextV);
                dp[i + 1][j + 1][k2] = nextV;
                ans = max(ans, nextV);
            }
        }
    }
    cout << ans << endl;
    return 0;
}