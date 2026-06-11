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
int LtoR[100010], RtoL[100010];
int lower[100010], upper[100010];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    rep(i, N) cin >> LtoR[i + 1];
    rep(i, N) cin >> RtoL[i];
    RtoL[N] = 0;
    int ans = 1;
    lower[0] = 1;
    upper[0] = 1000000000;
    rep(i, N) {
        if (LtoR[i] < LtoR[i + 1]) {
            lower[i] = upper[i] = LtoR[i + 1];
        } else {
            lower[i] = 1;
            upper[i] = min(RtoL[i], LtoR[i]);
        }
    }
    rrep(i, N - 1) {
        if (RtoL[i] > RtoL[i + 1]) {
            lower[i] = max(lower[i], RtoL[i]);
            upper[i] = min(upper[i], RtoL[i]);
        }
        
    }
    rep(i, N) {
        //cout << i << " " << lower[i] << " " << upper[i] << endl;
        ans = (ans * max(0LL, upper[i] - lower[i] + 1)) % mod;
    }
    cout << ans << endl;



    return 0;
}
