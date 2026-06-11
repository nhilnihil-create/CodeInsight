#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1000000007;
string in;
ll n;
ll dp[5005][5005];

ll modexp(ll b, ll e, ll m){
    ll r = 1;
    while(e > 0){
        if((e & 1) == 1){
            r = (r * b) % m;
        }
        e = e / 2;
        b = (b * b) % m;
    }
    return r;
}

int main(){
    cin >> n >> in;
    int p = in.size();

    dp[0][0] = 1;
    for(int x = 1 ; x <= n; x++){
        for(int y = 0 ; y <= n; y++){
            if(y != 0) dp[x][y] += (dp[x - 1][y - 1] * 2) % mod;
            else dp[x][y] += dp[x - 1][y];
            dp[x][y] += dp[x - 1][y + 1];
            dp[x][y] %= mod;

            //printf("haha %d %d %lld\n",x,y,dp[x][y]);     
        }
    }
    ll ans = dp[n][p];
    ll now = modexp(2,mod - 2, mod);

    for(int x = 1; x <= p; x++){
        ans = (ans * now) % mod;
    }
    printf("%lld\n",ans);
}
