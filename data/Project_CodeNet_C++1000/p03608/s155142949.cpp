#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 500000000
#define mod 1000000007
#define INF2 1000000000000000000

int d[210][210];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, R;
    cin >> N >> M >> R;
    rep(i, N) rep(j, N) d[i][j] = INF;
    rep(i, N) d[i][i] = 0;
    int r[10];
    rep(i, R) cin >> r[i];
    rep(i, R) r[i]--;
    sort(r, r + R);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll ans = INF;
    do{
        ll tmp = 0;
        rep(i, R - 1) {
            tmp += d[r[i]][r[i + 1]];
            //cout << r[i] << " " << r[i + 1] << "->" << d[r[i]][r[i + 1]] << endl;
        }
       // cout << tmp << endl;
        ans = min(ans, tmp);
    }while(next_permutation(r, r + R));
    cout << ans << endl;


    return 0;
}
