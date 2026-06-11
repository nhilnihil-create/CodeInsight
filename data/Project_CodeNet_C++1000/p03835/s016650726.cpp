#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int k, s;
    cin >> k >> s;
    int ans = 0;
    rep(x, k+1) {
        rep(y, k+1) {
            int z = s - x - y;
            if (z >= 0 && z <= k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
