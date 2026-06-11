#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];

    int ans = 1, u = 0;
    rep(i, n - 1) {
        if (a[i + 1] == a[i]) {
            if (i == u) u++;
            continue;
        }
        if (a[i + 1] > a[i] != a[u + 1] > a[u]) {
            ans++;
            u = i + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
