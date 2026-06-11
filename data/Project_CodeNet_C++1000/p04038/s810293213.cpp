#include<bits/stdc++.h>

using namespace std;

typedef long long int_t;

int_t fact[4000000],finv[4000000];
const int_t mod = 1000000007;
int_t dp[2010][2010];

int_t C(int_t a,int_t b){
    return fact[a] * finv[b] % mod * finv[a-b] % mod;
}

int main(){
    int_t n,k; cin>>n>>k;
    if(k == 1){ cout<< 1; return 0;}
    fact[0] = fact[1] = finv[1] = finv[0] = dp[0][0] = 1;
    for(int_t i=2;i<4000000;i++) fact[i] = fact[i-1] * i % mod, finv[i] = (mod - mod / i) * finv[mod % i] % mod;
    for(int_t i=2;i<4000000;i++) finv[i] = finv[i] * finv[i-1] % mod;
    for(int_t i=1;i<=n;i++)
        for(int_t j=0;j<=i;j++){
            dp[i][j] = dp[i-1][j];
            if(j) dp[i][j] = (dp[i][j] + dp[i][j-1] * (n - j + 1) % mod * C(n - i + (n - j + 1) * (k - 1) - 1, k - 2)%mod)%mod;
        }
    cout<<dp[n][n];
}