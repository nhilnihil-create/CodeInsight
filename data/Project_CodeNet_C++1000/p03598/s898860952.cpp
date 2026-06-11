#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    int central = k / 2;

    long ans = 0;
    rep(i, n) {
        if(x[i] <= central) {
            ans += 2 * x[i];
        } else {
            ans += 2 * (k - x[i]);
        }
    }
    cout << ans << endl;
}