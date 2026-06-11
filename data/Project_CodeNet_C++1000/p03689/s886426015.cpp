#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MN = 505;

ll sum, ans[MN][MN];

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int H, W, h, w; cin >> H >> W >> h >> w;

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            ans[i][j] = i%h == h-1 && j%w == w-1 ? -4000*h*w+3999 : 4000,
            sum += ans[i][j];

    if (sum > 0) {
        cout << "Yes";
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                cout << " \n"[!j] << ans[i][j];
    }
    else {
        cout << "No";
    }
}
