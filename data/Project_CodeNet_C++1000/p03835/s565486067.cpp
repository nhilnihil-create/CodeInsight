/**
*    created: 21.06.2020 00:14:16
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int k, s;
    cin >> k >> s;
    int cnt = 0;
    rep(x,k+1) {
        rep(y,k+1) {
            int z = s - x - y;
            if (0 <= z && z <= k) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}