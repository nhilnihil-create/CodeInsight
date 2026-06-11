#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N,C,K; cin>>N>>C>>K;
  vector<ll> T(N);
  rep(i,N)
  {
    cin>>T.at(i);
  }
  sort(T.begin(),T.end());
  
  ll ans=0;
  ll judge=T.at(0),hoge=0;
  rep(i,N)
  {
    if(i==N-1) {ans++;}
    if(T.at(i)>judge+K) {judge=T.at(i); hoge=i; ans++; continue;}
    if(i==N-1) {break;}
    if(i-hoge+1==C) {judge=T.at(i+1); hoge=i+1; ans++; continue;}
  }
  cout<<ans<<endl;
  return 0;
}
