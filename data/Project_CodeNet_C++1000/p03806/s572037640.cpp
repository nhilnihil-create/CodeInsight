#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;

const int MX = 505;
int dp[MX][MX];

int main(){
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    rep(i, MX) rep(j, MX) {
        dp[i][j] = INF;
    }
    dp[0][0] = 0;
    rep(i, n) rrep(j, MX) rrep(k, MX) {
        if (j-a[i]>=0 && k-b[i]>=0) {
            chmin(dp[j][k], dp[j-a[i]][k-b[i]] + c[i]);
        }
    }
    int ans = INF;
    int x = ma;
    int y = mb;
    while (1) {
        chmin(ans, dp[x][y]);
        x += ma;
        y += mb;
        if (x>=MX || y>=MX) break;
    }
    if (ans==INF) ans = -1;
    
    cout << ans << endl;
    return 0;
}
