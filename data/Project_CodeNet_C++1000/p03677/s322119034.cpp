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
int a[100010];
int sum[200010];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    int normal = 0;
    rep(i, n - 1) normal += (a[i + 1] + m - a[i]) % m;
    rep(i, n - 1) {
        if (a[i] < a[i + 1]) {
            sum[a[i]+m + 1]++;
            sum[a[i + 1]+m + 1] += a[i + 1] - a[i] - 1;
            sum[a[i + 1]+m] -= a[i + 1] - a[i];
        } else {
            sum[a[i] + 1]++;
            sum[a[i]+m + 1]++;
            sum[a[i + 1]+m + 1] += a[i + 1]+m - a[i] - 1;
            sum[a[i + 1]+m] -= a[i + 1]+m - a[i];
        }
    }
    rep(j, 2) rep(i, m * 2) sum[i + 1] += sum[i];
    //rep(i, m * 2 + 1) cout << i << " " << sum[i] << endl;
    int ans = 0;
    REP(i, m, 2 * m) ans = max(ans, sum[i]);
    cout << normal - ans << endl;


    return 0;
}
