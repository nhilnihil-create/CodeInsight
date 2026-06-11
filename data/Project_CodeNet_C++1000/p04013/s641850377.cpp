#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';
bool cmp(pair<ll,ll> a, pair<ll,ll> b) { return a.second > b.second; }

int main(){
    ll n,a; cin >> n >> a; vl x(n);
    rep(i,n){
        cin>>x[i];
        x[i]-=a;
    }
    vvl dp(n+1,vl(5000));
    dp[0][n*a] = 1;
    rep(i,n){
        rep(j,2*n*a){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j+x[i]] += dp[i][j];
        }
    }
    cout << dp[n][n*a] - 1 << endl;
}