#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a[100010];
    rep(i, n) cin >> a[i];
    int ans = INF2;
    rep(k, 2) {
        int sum[100010] = {};
        int tmp = 0;
        rep(i, n) {
            sum[i + 1] = sum[i] + a[i];
            bool isplus = (i + k) % 2;
            if(isplus && sum[i + 1] <= 0) {
                tmp += 1 - sum[i + 1];
                sum[i + 1] = 1;
            } else if (!isplus && sum[i + 1] >= 0) {
                tmp += sum[i + 1] + 1;
                sum[i + 1] = -1;
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
