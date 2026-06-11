#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N,M,K; cin>>N>>M>>K;
  rep(i,N+1)
  {
    rep(j,M+1)
    {
      if(i*j+(N-i)*(M-j)==K) {cout<<"Yes"<<endl; return 0;}
    }
  }
  cout<<"No"<<endl;
  return 0;
}
