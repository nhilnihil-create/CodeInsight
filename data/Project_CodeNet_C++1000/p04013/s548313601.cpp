#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////

ll dp[52][52][2510];

int main() {
    int n, a; cin >> n >> a;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    rep(i,n) rep(j,n+1) rep(k,a*n+1) {
        dp[i+1][j][k] += dp[i][j][k];
        dp[i+1][j+1][k+x[i]] += dp[i][j][k];
    }
    ll ans = 0;
    repf(j,1,n+1) {
        ans += dp[n][j][a*j];
    }
    cout << ans << endl;
    return 0;
}
