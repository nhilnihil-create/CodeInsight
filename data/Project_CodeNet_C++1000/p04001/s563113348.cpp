#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;

ll keta(ll n)
{
  ll k = 0;
  while(n != 0)
  {
    n /= 10;
    k++;
  }
  return k;
}  

ll ll_pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
  return ret;
}  

int main() 
{
  ll S; cin>>S;
  ll K=keta(S)-1;
  ll sum=0;
  ll kijun=10;
  rep(i,1<<K)
  {
    ll S2=S;
    ll i2=i;
    rep(j,K)
    {
      if(i2&1)
      {
        sum+=S2%kijun;
        S2/=kijun;
        kijun=1;
      }
      //cout<<sum<<endl;
      i2>>=1;
      kijun*=10;
    }
    sum+=S2;
    kijun=10;
    //cout<<sum<<endl;
  }  
  cout<<sum<<endl;
  return 0;
}