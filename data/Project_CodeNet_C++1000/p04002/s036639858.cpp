#include <bits/stdc++.h>
//#include <ext/numeric>
#define oo 0x3f3f3f3f
#define long long long

using namespace std;
//using namespace __gnu_cxx;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(9), cout << fixed;

    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> arr(n);
    set<pair<int, int>> isBlack;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        isBlack.insert({arr[i].first, arr[i].second});
    }

    map<int, long> ans;
    ans[0] = 1ll * (h - 2) * (w - 2);
    set<pair<int, int>> vis[3][3];
    for (int i = 0; i < n; ++i) {
        for (int x = max(1, arr[i].first - 2); x <= arr[i].first; ++x) {
            for (int y = max(1, arr[i].second - 2); y <= arr[i].second; ++y) {
                if (x + 2 > h || y + 2 > w)
                    continue;
                bool ok = true;
                int cnt = 0;
                for (int a = x; a <= x + 2; ++a) {
                    for (int b = y; b <= y + 2; ++b) {
                        if (isBlack.count({a, b})) {
                            ++cnt;
                            ok &= vis[a - x][b - y].insert({a, b}).second;
                        }
                    }
                }
//                cout << x << ' ' << y << ' ' << cnt << '\n';
                if (ok) {
                    ++ans[cnt];
                    --ans[0];
                }
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
