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
int p[100010], q[100010];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int W, H;
    cin >> W >> H;
    rep(i, W) cin >> p[i];
    rep(i, H) cin >> q[i];
    sort(p, p + W);
    sort(q, q + H);
    int ans = 0;
    int i = 0, j = 0;
    while(i + j < W + H) {
        int P = INF, Q = INF;
        if (i < W) P = p[i];
        if (j < H) Q = q[j];
        int num = min(P, Q);
        if (P < Q) {
            i++;
            ans += ((H - j) + 1) * num;
        }
        else {
            j++;
            ans += ((W - i) + 1) * num;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
