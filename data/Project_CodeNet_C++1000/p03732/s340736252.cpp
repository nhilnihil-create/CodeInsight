#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

ll dp[105][105][305];

int main(){
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n);
    vector<ll> v(n);
    rep(i, n) cin >> w[i] >> v[i];
    dp[0][0][0] = 0;
    for (ll i=1; i<=n; i++) {
        for (ll j=0; j<=i; j++) {
            for (ll k=0; k<=3*j; k++) {
                ll total = w[0]*j + k;
                if (total>W) continue;
                dp[i][j][k] = dp[i-1][j][k];
                ll iw = w[i-1] - w[0];
                ll iv = v[i-1];
                if (j>0 && k-iw>=0) {
                    chmax(dp[i][j][k], dp[i-1][j-1][k-iw]+iv);
                }
            }
        }
    }
    ll ans = 0;
    rep(j, 105) rep(k, 305) {
        chmax(ans, dp[n][j][k]);
    }
    
    cout << ans << endl;
    return 0;
}
