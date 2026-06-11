#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int a[n+1] = {};
    rep(i,n) cin >> a[i];
    int64_t ans = 0;
    rep(i,n) {
        ans += a[i]/2;
        a[i] %= 2;
        if (a[i+1] > 0 && a[i] == 1) {
            ans++;
            a[i+1]--;
        }
    }
    cout << ans << endl;
}