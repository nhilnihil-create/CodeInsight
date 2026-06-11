#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int n;
    cin >> n;
    map<int, int> f;
    rep(i, 0, n) {
        int x;
        cin >> x;
        ++f[x];
    }
    long long ans = 0LL;
    vector<int> a;
    for (auto it : f) {
        if (it.second >= 4) ans = 1LL * it.first * it.first;
        if (it.second >= 2) a.push_back(it.first);
    }
    if (sz(a) >= 2) ans = max(ans, 1LL * a.back() * a[sz(a) - 2]);
    cout << ans << '\n';
}