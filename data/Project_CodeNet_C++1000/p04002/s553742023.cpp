#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

// 3ヶ月ほど前に解説見て放置してた。解答のアイデアを思い起こして実装した。
// 要するに解説を見たということです(おいおい

ll H, W;
int N;
typedef pair<ll, ll> P;
vector<ll> ans(10);
map<P, int> val;

int main() {
    cin >> H >> W >> N;
    ans[0] = (H - 2) * (W - 2);

    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> y >> x;
        y--; x--;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                ll nx = x + dx, ny = y + dy;
                if (nx <= 0 || nx >= W-1 || ny <= 0 || ny >= H-1) continue;

                if (val.find(P(nx, ny)) == val.end()) {
                    val[P(nx, ny)] = 1;
                    ans[0]--;
                    ans[1]++;
                } else {
                    int aft = val[P(nx, ny)] + 1;
                    val[P(nx, ny)]++;
                    ans[aft - 1]--;
                    ans[aft]++;
                }
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}