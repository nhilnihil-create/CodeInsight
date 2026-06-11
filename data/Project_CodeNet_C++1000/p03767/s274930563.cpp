#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >> n;
    vector<long> a(3*n);
    rep(i, 3*n) { cin >> a[i]; }
    sort(a.rbegin(), a.rend());
    unsigned long long ans = 0;
    int idx = 1;
    for(int i = 0; i < n; i++) {
        ans += a[idx];
        idx += 2;
    }
    cout << ans << endl;
}