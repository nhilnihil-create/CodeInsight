#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> p(n);
    vector<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        for (int x = -2; x <= 0; x++) {
            for (int y = -2; y <= 0; y++) {
                st.emplace_back(p[i].first + x, p[i].second + y);
            }
        }
    }
    sort(p.begin(), p.end());
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    vector<ll> ans(10);
    for (auto z : st) {
        int x, y;
        tie(x, y) = z;
        int s = 0;
        if (x <= 0 || y <= 0 || x > h - 2 || y > w - 2) continue;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                pair<int, int> t = {i, j};
                s += (int)binary_search(p.begin(), p.end(), t);
            }
        }
        ans[s]++;
    }
    ans[0] = (ll)(h - 2) * (ll)(w - 2);
    for (int i = 1; i < 10; i++) {
        ans[0] -= ans[i];
    }
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}