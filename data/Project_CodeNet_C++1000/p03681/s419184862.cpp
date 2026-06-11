#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;

ll beki(ll n,vector<ll> &num)
{
  if(n==1) {num.at(0)=1; return 1;}
  if(num.at(n-1)!=0) {return num.at(n-1);}
  num.at(n-1)=beki(n-1,num)*n%MOD; return num.at(n-1);
}  


int main() 
{
  ll N,M; cin>>N>>M;
  ll mi=min(N,M);
  ll ma=max(N,M);
  vector<ll> num(ma,0);
  //cout<<ma-mi<<endl;
  if(ma-mi==0)
  {
    cout<<2*beki(N,num)*beki(M,num)%MOD<<endl;
    //cout<<beki(N,num)<<" "<<beki(M,num)<<endl;
    return 0;
  }
  if(ma-mi==1)
  {
    cout<<beki(N,num)*beki(M,num)%MOD<<endl; return 0;
  }
  cout<<0<<endl; return 0;
  return 0;
}