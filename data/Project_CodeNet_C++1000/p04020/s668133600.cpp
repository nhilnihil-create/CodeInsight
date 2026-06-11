#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
const int INF = 1e18, MOD = 998244353;
signed main() {
    int n, cnt = 0, ans = 0, a;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>a;
        if (a == 0) ans += cnt / 2, cnt = 0;
        else cnt += a;
    }
    ans += cnt / 2, cnt = 0;
    cout<<ans<<endl;
}