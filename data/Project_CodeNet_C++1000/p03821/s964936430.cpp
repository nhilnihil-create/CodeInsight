#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N; cin>>N;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i,N)
  {
    cin>>A.at(i)>>B.at(i);
  }
  reverse(A.begin(),A.end());
  reverse(B.begin(),B.end());
  
  ll ans=0;
  rep(i,N)
  {
    ll amari=(A.at(i)+ans)%B.at(i);
    if(amari!=0) {ans+=B.at(i)-amari;}
  }
  cout<<ans<<endl;
  return 0;
}
