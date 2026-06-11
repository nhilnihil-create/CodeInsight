#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    int ans = 1e9;
    for (int i = -100; i <= 100; i++) {
        int cost = 0;
        rep(j, n) cost += (a[j] - i) * (a[j] - i);
        ans = min(ans, cost);
    }

    cout << ans << endl;
    return 0;
}
