#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for(auto &e : a) cin >> e;
    vector<int64_t> sum(n + 1), pos(n + 1);
    for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + a[i];
    for(int i = 0; i < n; ++i) pos[i + 1] = pos[i] + (a[i] > 0 ? a[i] : 0);
    int64_t ans = 0;
    for(int i = 0; i + k - 1 < n; ++i) {
        int j = i + k;
        int64_t add = sum[j] - sum[i];
        int64_t sub = pos[j] - pos[i];
        ans = max(ans, pos[n] - sub);
        ans = max(ans, pos[n] - sub + add);
    }
    cout << ans << '\n';
    return 0;
}
