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
int a[310][310];
int b[310][310];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    rep(i, N) rep(j, N) cin >> a[i][j];
    rep(i, N) rep(j, N) b[i][j] = a[i][j];
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }
    int ans = 0;
    rep(i, N) {
        rep(j, N) {
            if (a[i][j] != b[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    rep(i, N) {
        rep(j, N) { 
            bool exist = false;
            rep(k, N) {
                if (i == k || j == k) continue;
                if (a[i][k] + a[k][j] == a[i][j]) {  
                    exist = true;
                }
            }
            if (!exist) ans += a[i][j];
        }
    }

    cout << ans/2 << endl;

    return 0;
}
