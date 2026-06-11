#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, t;
    cin >> n >> t;
    int tm[n];
    for (int i = 0; i < n; i++) cin >> tm[i];
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += min(t, tm[i + 1] - tm[i]);
    }
    ans += t;
    cout << ans << endl;
    return 0;
}