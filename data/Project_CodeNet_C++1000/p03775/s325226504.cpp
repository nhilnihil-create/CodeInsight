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

ll keta(ll n)
{
  ll k=0;
  while(n!=0)
  {
    n/=10;
    k++;
  }
  return k;
}  

int main() 
{
  ll N; cin>>N;
  ll ans=INF;
  for(ll a=1;a*a<=N;a++)
  {
    if(N%a==0)
    {
      chmin(ans,keta(N/a));
      //int b=1;
    }
    //cout<<a;
  }
  cout<<ans<<endl;
  return 0;
}
