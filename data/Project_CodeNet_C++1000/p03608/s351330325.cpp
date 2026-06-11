#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
const lint MOD =1000000007;
const lint MAX = 10000000;
using Graph =vector<vector<lint>>;
typedef pair<lint,lint> P;
 
 
lint fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() 
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (lint i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long COM(lint n, lint k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
lint primary(lint num)
{
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0;
 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
 
    return 1;
}
   long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
    lint lcm(lint a,lint b){
        return a/__gcd(a,b)*b;
    }
     lint gcd(lint a,lint b){
        return __gcd(a,b);
    }    
  lint  dp[2005][2005];
  int main(){
     lint n,m,r;
     cin>>n>>m>>r;
     lint f[r];
     rep(i,r)cin>>f[i];
     rep(i,2005){
         rep(j,2005){
             if(i==j)dp[i][j]=0;
             else dp[i][j]=INF;
         }
     }
     rep(i,m){
         lint a,b,c;
         cin>>a>>b>>c;
         dp[a][b]=c;
         dp[b][a]=c;
     }
     repp(k,1,n+1){
        repp(i,1,n+1){
            repp(j,1,n+1){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
     }
    sort(f,f+r);
    lint ans=0;
    rep(i,r-1){
        ans+=dp[f[i]][f[i+1]];
    }
    while(next_permutation(f,f+r)){
        lint sum=0;
            rep(i,r-1){
                    sum+=dp[f[i]][f[i+1]];
            }
            ans=min(sum,ans);
    }
    cout<<ans;
  }
  
  
     
  