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


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    ll ans = 0;
    ll add = 0;
    int a[100010], b[100010];
    rep(i, N) cin >> a[i] >> b[i];
    RREP(i, N - 1, 0) {
        ans += (b[i] - (a[i] + add) % b[i]) % b[i];
        add += (b[i] - (a[i] + add) % b[i]) % b[i];
        //cout << ans << " " << add << endl;
    }
    cout << ans << endl;

    return 0;
}
