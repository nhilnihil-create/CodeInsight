#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
constexpr ll MOD = ll(1e9)+7;

ll power(ll x, ll n){
    ll res = 1;
    x %= MOD;
    n %= MOD-1;
    while(n > 0){
        if(n&1) res = res*x%MOD;
        x = x*x%MOD;
        n >>= 1;
    }
    return res;
}

ll dp[5005][5005]{};

int main(){
    int n;
    string s;
    cin >> n >> s;
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] %= MOD;
            dp[i+1][j+1] += dp[i][j]*2;
            dp[i+1][max(j-1,0)] += dp[i][j];
        }
    }
    cout << dp[n][s.size()]*power(2,s.size()*(MOD-2))%MOD << endl;
    return 0;
}
