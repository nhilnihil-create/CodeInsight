#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef pair<ui, ll> pii;

int n; ui k;
ll ans;
vector<pii> nums[35];
ll ut[35];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ui x; ll y;
        cin >> x >> y;
        int idx;
        if (x == 0) idx = 0;
        else idx = 32 - __builtin_clz(x);
        nums[idx].emplace_back(x, y);
        ut[idx] += y;
    }
    while (k) {
        int idx = 32 - __builtin_clz(k);
        ll cur = 0;
        for (int i = 0; i < idx; i++) cur += ut[i];
        ans = max(cur, ans);
        k ^= 1<<(idx-1);
        for (auto p : nums[idx]) {
            ui x; ll y;
            tie(x, y) = p;
            x ^= 1 << (idx-1);
            int idx2 = (x == 0) ? 0 : 32 - __builtin_clz(x);
            nums[idx2].emplace_back(x, y);
            ut[idx2] += y;
        }
    }
    ans = max(ans, ut[0]);
    cout << ans << '\n';
    return 0;
}
