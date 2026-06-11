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
    int N, K;
    cin >> N >> K;
    int sum = 0;
    int a[100010];
    rep(i, N) cin >> a[i];
    rep(i, N) {
        sum += max(0LL, a[i]);
    }
    int ans = 0;
    int tmp1 = 0, tmp2 = 0;
    rep(i, K) {
        tmp1 -= max(0LL, a[i]);
        tmp2 += a[i];
    }
    rep(i, N - K + 1) {
        ans = max(ans, sum + tmp1 + max(0LL, tmp2));
        //cout << sum << " " << tmp1 << " " << tmp2 << endl;
        tmp1 += max(0LL, a[i]);
        tmp1 -= max(0LL, a[K + i]);
        tmp2 -= a[i];
        tmp2 += a[K + i];
        
    }
    cout << ans << endl;


    return 0;
}
