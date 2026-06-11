#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, x, ans = 0;
    cin >> n >> x;
    vector<int64_t> a(n);
    for (auto i = 0; i < n; i++) cin >> a[i];
    for (auto i = 0; i < n - 1; i++) {
        int64_t cnt = a[i] + a[i + 1] - x;
        if (cnt > 0)
            ans += cnt, a[i + 1] -= min(cnt, a[i + 1]);
    }
    cout << ans << endl;
    return 0;
}