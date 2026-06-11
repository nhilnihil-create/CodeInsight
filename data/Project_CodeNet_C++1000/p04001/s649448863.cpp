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
//2^iの位の数を返す
ll pla(ll n,ll i)
{
  ll x = pow(2,i + 1),y = pow(2,i);
  return n % x / y;
}



int main() 
{
  ll S; cin>>S;
  ll K=keta(S)-1;
  ll ans=0;
  rep(i,pow(2,K))
  {
    ll moto=S;
    for(ll j=K;j>=0;j--)
    {
      if(j==0||pla(i,j-1)==1)
      {
        ll p=pow(10,j);
        ans+=moto/p;
        //cout<<moto/p<<endl;
        moto%=p;
        //cout<<moto<<" "<<ans<<endl;
      }  
    }  
  } 
  cout<<ans<<endl;
  return 0;
}