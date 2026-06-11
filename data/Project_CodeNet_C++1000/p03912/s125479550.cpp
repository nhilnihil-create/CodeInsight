#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
const lint MOD =1000000007;
const lint MAX = 1000000;
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
  int main(){
      lint n,m;
      lint ans=0;
      cin>>n>>m;
      vector<vector<lint>> g(m);
      rep(i,n){
          lint a;
          cin>>a;
        g[a%m].push_back(a);
      }
      repp(i,1,(m+1)/2){
          lint dif=0;
          lint comp=0;
          lint count=1;
          if(g[i].size()<g[m-i].size()){
              ans+=g[i].size();
              dif=g[m-i].size()-g[i].size();
              sort(all(g[m-i]));
              rep(j,g[m-i].size()-1){
                  if(g[m-i][j]==g[m-i][j+1])count++;
                  else{
                      comp+=count/2;
                      count=1;
                  }
              }
              comp+=count/2;
          }else if(g[i].size()>g[m-i].size()){
              ans+=g[m-i].size();
              dif=g[i].size()-g[m-i].size();
              sort(all(g[i]));
              rep(j,g[i].size()-1){
                  if(g[i][j]==g[i][j+1])count++;
                  else{
                      comp+=count/2;
                      count=1;
                  }
              }
              comp+=count/2;
          }else{
              ans+=g[i].size();
          }
          dif/=2;
          ans+=min(comp,dif);
      }
      if(m%2==0)ans+=g[m/2].size()/2;
      ans+=g[0].size()/2;
      cout<<ans;
  }
  
     
