#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

signed main() {
    int k, t;
    cin>>k>>t;
    int a;
    int mx = -INF;
    for (int i = 0; i < t; i++) {
        cin>>a;
        mx = max(mx, a);
    }
    cout<<max(0ll, mx - 1 - k + mx)<<endl;
}
