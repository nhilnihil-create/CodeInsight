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
using ll = long long;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
///////////////////////////////////////////////

const ll inf = 5000;
ll dp[50][410][410];

int main() {
    int n, ma, mb; cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];

    rep(i,n+1) rep(j,401) rep(k,401) {
        dp[i][j][k] = inf;
    }

    dp[0][0][0] = 0;
    rep(i,n) rep(j,400) rep(k,400) {
        if (a[i]+j<=400 && b[i]+k<=400) {
            chmin(dp[i+1][a[i]+j][b[i]+k], dp[i][j][k]+c[i]);
        }
        chmin(dp[i+1][j][k], dp[i][j][k]);
    }

    ll ans = inf;
    int aa=ma, bb=mb;
    while(aa<=400 && bb<=400) {
        chmin(ans, dp[n][aa][bb]);
        aa+=ma, bb+=mb;
    }

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}