#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<ll>> dp(n, vector<ll>(n, inf));
    vector<ll> v(r);
    rep(i, r){
        cin >> v[i];
        v[i]--;
    }
    sort(all(v));
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    rep(i, n)dp[i][i] = 0;
    rep(k, n)rep(i, n)rep(j, n){
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
    }
    ll ans = inf;
    do{
        ll now = 0;
        rep(i, r-1){
            now += dp[v[i]][v[i+1]];
        }
        ans = min(ans, now);
    }while(next_permutation(all(v)));
    cout << ans << endl;
}
