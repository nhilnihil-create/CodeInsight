#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<vector<ll>> Comtable;
ll C(ll n,ll r)
{
  if(n==r) return 1;
  if(r==0) return 1;
  if(Comtable.at(n).at(r)>0) return Comtable.at(n).at(r);
  Comtable.at(n).at(r)=C(n-1,r)+C(n-1,r-1);
  return Comtable.at(n).at(r);
}  

int main() 
{
  ll N,P; cin>>N>>P;
  ll num0=0,num1=0;
  rep(i,N)
  {
    ll A; cin>>A;
    A%=2;
    if(A==0) num0++;
    else num1++;
  }
  ll hoge=0;
  Comtable=vector<vector<ll>>(51,vector<ll>(51,0));
  for(int r=P;r<=num1;r+=2)
  {
    hoge+=C(num1,r);
  }
  cout<<(ll)pow(2,num0)*hoge<<endl;
  return 0;
}
