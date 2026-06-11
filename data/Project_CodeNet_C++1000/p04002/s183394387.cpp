#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w, n; cin >> h >> w >> n;
    set<pair<int, int>> cand, black;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b; a--, b--;
        black.insert(make_pair(a, b));
        for (int dy = -1; dy <= 1; dy++) {
            if (a + dy <= 0 || a + dy >= h - 1) continue;
            for (int dx = -1; dx <= 1; dx++) {
                if (b + dx <= 0 || b + dx >= w - 1) continue;
                cand.insert(make_pair(a + dy, b + dx));
            }
        }
    }

    vector<ll> ans(10);
    ans[0] = 1LL * (h - 2) * (w - 2) - (ll)cand.size();
    for (auto &p: cand) {
        int y = p.first, x = p.second;
        int cnt = 0;
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (black.count(make_pair(y + dy, x + dx))) cnt++;
            }
        }
        ans[cnt]++;
    }
    for (auto &e: ans) cout << e << endl;    
    return 0;
}
