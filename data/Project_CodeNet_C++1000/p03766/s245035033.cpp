#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007

using namespace std;

ll dp[3000100][2];

int main(){
    ios::sync_with_stdio(0);
    ll n;
    cin>>n;

    for(int i=n-1 ; i<=2*n+10 ;i ++){
        dp[i][0] = n;
        dp[i][1] = n;
    }
    ll r = n*(n-1);
    r %= mod;
    for(int i = n-2; i>=0 ; i--){
        dp[i][0] = dp[i+1][0];
        dp[i][1] = dp[i+1][0];
        dp[i][1] += ((n-1))%mod;
        dp[i][1] %= mod;
        dp[i][0] += r;
        dp[i][0] %= mod;
        r -= dp[i+n][1];
        r %= mod;
        r += mod;
        r %= mod;
        r += dp[i+1][1];
    }
    cout<<dp[0][0]<<endl;
    return 0;
}
