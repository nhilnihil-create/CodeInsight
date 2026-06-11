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
    ll num = 0;
    ll A[100010], B[100010];
    rep(i, N) cin >> A[i] >> B[i];
    RREP(i, N - 1, 0) {
        A[i] += num;
        ll tmp = (B[i] - A[i] % B[i]) % B[i];
        num += tmp;
        ans += tmp;
    }
    cout << ans << endl;

    return 0;
}
