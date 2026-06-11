#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;


ll pla(ll n,ll i)
{
  ll x = pow(10,i + 1),y = pow(10,i);
  return n % x / y;
}

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


ll all(vector<ll> S)
{
  ll K=S.size();
  if(K==1) {return S.at(0);}
  
  vector<ll> S2=S;
  S2.at(K-2)=S2.at(K-2)*pow(10,keta(S2.at(K-1)))+S2.at(K-1);
  S2.pop_back();
  ll s=S.at(K-1);
  S.pop_back();
  /*cout<<"S=";
  rep(i,K-1)
  {
    cout<<S.at(i)<<",";
  }
  cout<<"  ";
  cout<<"S2=";
  rep(i,K-1)
  {
    cout<<S2.at(i)<<",";
  }
  cout<<"  ";
  cout<<"s="<<s<<endl;*/
  return all(S)+all(S2)+s*pow(2,K-2);
}  



int main() 
{
  ll S; cin>>S;
  ll K=keta(S);
  vector<ll> Svec(K);
  rep(i,K)
  {
    Svec.at(i)=pla(S,K-i-1);
  }
  /*rep(i,K)
  {
    cout<<Svec.at(i)<<" ";
  }
  cout<<endl;*/
  cout<<all(Svec)<<endl;
  return 0;
}