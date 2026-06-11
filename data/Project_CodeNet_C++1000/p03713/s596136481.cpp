#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;

ll H, W;

ll ans;

void calc(ll h, ll max_h, ll max_w) {
    vector<ll> areas_1;
    vector<ll> areas_2;

    ll area1 = h * max_w;
    areas_1.push_back(area1);
    areas_2.push_back(area1);

    // 横線をひくパターン
    if (max_h - h >= 2) {
        ll area2_h = (max_h - h) / 2;
        ll area2 = area2_h * max_w;
        areas_1.push_back(area2);

        // 切り上げ
        ll area3_h = ceil((double)(max_h - h) / 2);
        ll area3 = area3_h * max_w;
        areas_1.push_back(area3);

        // printf("h: %d, area1: %d area2: %d, area3: %d\n", h, area1, area2, area3);
        sort(areas_1.begin(), areas_1.end());
        ans = min(ans, areas_1[areas_1.size() - 1] - areas_1[0]);
    }

    // 縦線をひく
    if (max_w >= 2) {
        ll area4_h = ceil((double)max_w / 2);
        ll area4 = area4_h * (max_h - h);
        ll area5_h = max_w / 2;
        ll area5 = area5_h * (max_h - h);
        areas_2.push_back(area4);
        areas_2.push_back(area5);
        // printf("h: %d, area1: %d area4: %d, area5: %d\n", h, area1, area4, area5);
        sort(areas_2.begin(), areas_2.end());
        ans = min(ans, areas_2[areas_2.size() - 1] - areas_2[0]);
    }

    // cout << ans << endl;
}

int main() {
    cin >> H >> W;

    ans = H * W;

    // A を決める
    for (int i = 1; i <= H - 1; i++) {
        calc(i, H, W);
    }

    for (int i = 1; i <= W - 1; i++) {
        calc(i, W, H);
    }

    cout << ans << endl;
}