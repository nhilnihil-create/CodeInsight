#include <bits/stdc++.h>
using namespace std;

#define int long long

#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int mod = 1E9 + 7;

int32_t main() {
    fastIO();
    
    int n, fl = 1, cnt = 1;
    cin >> n;
    
    vector<int> pre(n), suf(n), Max(n, -1), Min(n, -1);
    for (auto &x : pre) cin >> x;
    for (auto &x : suf) cin >> x;
    
    Max[0] = Min[0] = pre[0], Max[n - 1] = Min[n - 1] = suf[n - 1];
    if (pre[n - 1] > pre[n - 2]) fl = pre[n - 1] == suf[n - 1];
    
    for (int i = 1; i < n-1; ++i) {
        if (pre[i] > pre[i - 1]) Max[i] = Min[i] = pre[i];
        else Max[i] = pre[i], Min[i] = 1;
    }
    for (int i = n-2; i >= 0; --i) {
        if (suf[i] > suf[i + 1]) {
            fl &= Max[i] >= suf[i];
            Max[i] = Min[i] = suf[i];
        }
        else Max[i] = min(Max[i], suf[i]);
    }
    
    for (int i = 0; i < n; ++i) cnt = cnt * (Max[i] - Min[i] + 1) % mod;
    
    if (!fl) cout << 0 << "\n";
    else cout << cnt << "\n";
    
    return 0;
}