///In the name of GOD
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 30 + 10;
ll n, dp[MXN], sum;
string s;
ll num(ll l, ll r){
    ll nn = 0;
    for(int i = l; i <= r; i ++){
        nn *= 10;
        nn += (s[i] - '0');
    }
    return nn;
}
ll Pw(ll x){
    if(x <= 0) return 1;
    return (1LL << (x - 1));
}
ll solve(ll p){
    if(p == 0) return 0;
    if(dp[p]) return dp[p];
    ll ans = 0;
    for(int i = 1; i <= p; i ++){
        ll nnw = (solve(i - 1) + Pw(i - 1) *  num(i, p));
        ans += nnw;
    }
    return dp[p] = ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> s; n = s.size(), s = "@" + s;
    cout << solve(n);
    return 0;
}
/*!
    I CHOOSE TO HAVE FAITH,
    BECAUSE WITHOUT THAT,
    I HAVE NOTHING....
    ITS THE ONLY THING THAT'S KEEPING ME GOING.
*/
//! N.N
