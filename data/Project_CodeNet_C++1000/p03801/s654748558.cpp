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
    int n;
    cin >> n;
    vector<ll> a(n), ans(n), val(1);
    vector<int> pos(1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > a[pos.back()]) {
            pos.emplace_back(i);
            val.emplace_back(a[i]);
        }
    }
    val[0] = a[0];
    vector<ll> cnt(val.size()), d(val.size());
    for (int i = 0; i < n; i++) {
        int j = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
        d[j] += a[i];
        cnt[j]++;
    }
    for (int i = pos.size() - 1; i > 0; i--) {
        ans[pos[i]] = d[i] - cnt[i] * (val[i - 1]);
        cnt[i - 1] += cnt[i];
        d[i - 1] += cnt[i] * val[i - 1];
    }
    debug(pos, val, cnt);
    for (int i = 0; i < n; i++) {
        ans[0] += min(a[0], a[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
