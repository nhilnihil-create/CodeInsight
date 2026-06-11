#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), c(1e+5 + 10, 0);
    rep(i, n) {
        cin >> a[i];
        a[i]++;
    }

    rep(i, n) {
        int val = a[i];
        c[val - 1]++;
        c[val]++;
        c[val + 1]++;
    }

    int ans = 0;

    rep(i, 1e+5 + 5) ans = max(ans, c[i]);

    cout << ans << endl;

    return 0;
}
