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
    int N; cin >> N;
    int A[100010];
    rep(i, N) cin >> A[i];
    int ans = 0;
    int minimum = 0;
    //cout << "####" << endl;
    rep(i, N) {
        if (A[i] - minimum - 1 > 0) {
            int cnt = (A[i] - 1)/(minimum + 1);
            ans += cnt;
            A[i] = 1;
        }
        minimum = max(minimum, A[i]);
        //cout << A[i] << " " << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
