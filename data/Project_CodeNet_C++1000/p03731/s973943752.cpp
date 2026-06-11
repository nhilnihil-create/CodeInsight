#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int n;
    cin >> n;
    int t;
    cin >> t;
    int z;
    cin >> z;
    int ans = 0;
    rep(i, 1, n) {
        int x;
        cin >> x;
        int nz = z + t;
        if (x < z) continue;
        if (x >= nz) {ans += t; z = x; nz = x + t; continue;}
        ans += x - z;
        z = x;
        nz = x + t;
    }
    ans += t;
    cout << ans << '\n';
}