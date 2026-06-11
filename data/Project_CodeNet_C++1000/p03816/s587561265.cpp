#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> f;
    rep(i, 0, n) {
        int x;
        cin >> x;
        ++f[x];
    }
    vector<int> cnt(10, 0);
    for (auto &it : f) {
        if (it.second % 2 == 1) it.second = 1;
        else it.second = 2;
        ++cnt[it.second];
    }
    int ans = cnt[1];
    if (cnt[2] % 2 == 0) ans += cnt[2];
    else ans += cnt[2] - 1;
    cout << ans << '\n';
}