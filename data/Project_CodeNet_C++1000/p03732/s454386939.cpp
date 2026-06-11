#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()
 
int main(){
    ll n,w;
    cin >> n >> w;
    vector<vector<ll>> v(4);
    ll w1,v1;
    cin >> w1 >> v1;
    v[0].push_back(v1);
    for(int i = 1; i < n; i++){
        ll x,y;
        cin >> x >> y;
        v[x-w1].push_back(y);
    }
    rep(i, 4)sort(ALL(v[i]), greater<ll>());

    ll dp[4][101] = {};
    rep(i, 4)rep(j, v[i].size())dp[i][j+1] = dp[i][j] + v[i][j];
 
    ll ans = 0;
    rep(i,v[0].size()+1)rep(j,v[1].size()+1)rep(k,v[2].size()+1)rep(l,v[3].size()+1){
        ll weight = w1*i + (w1+1)*j + (w1+2)*k + (w1+3)*l;
        if(weight > w) continue;
        ll value = dp[0][i] + dp[1][j] + dp[2][k] + dp[3][l];
        ans = max(ans, value);
    }
    cout << ans << endl;
}