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
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    rep(i, N) {
        int L = C * i - D * (N - i - 1);
        int R = D * i - C * (N - i - 1);
        if (L <= (B - A) && (B - A) <= R) {
            cout << "YES" << endl;
            //cout << i << " " << N - i - 1 << endl;
            //cout << L << " " << (B - A) << " " << R << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
