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
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

ll dp[55][55][2600];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    dp[0][0][0] = 1;
    rep1(i, n) {
        for (int j=0; j<=i; j++) {
            for (int k=0; k<2600; k++) {
                dp[i][j][k] += dp[i-1][j][k];
                if (j>0 && k-x[i-1]>=0) {
                    dp[i][j][k] += dp[i-1][j-1][k-x[i-1]];
                }
            }
        }
    }
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        int sum = a*i;
        ans += dp[n][i][sum];
    }
    
    cout << ans << endl;
    return 0;
}
