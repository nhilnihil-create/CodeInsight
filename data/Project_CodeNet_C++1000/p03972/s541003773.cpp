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
typedef pair<int, int> P;

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int W, H;
    cin >> W >> H;
    vector<P> pq;
    rep(i, W) {int p; cin >> p; pq.push_back({p, 0LL});}
    rep(i, H) {int q; cin >> q; pq.push_back({q, 1LL});}

    sort(pq.begin(), pq.end());
    int a = W + 1, b = H + 1;
    int ans = 0;
    rep(i, W + H) {
        if (pq[i].second == 0) {ans += b * pq[i].first; a--;}
        else {ans += a * pq[i].first; b--;}
    }
    cout << ans << endl;

    return 0;
}
