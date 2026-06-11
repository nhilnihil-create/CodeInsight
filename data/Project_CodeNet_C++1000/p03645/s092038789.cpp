#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N,M; cin>>N>>M;
  vector<ll> keiyu(N,0);
  rep(i,M)
  {
    ll a,b; cin>>a>>b;
    a--; b--;
    if(a==0||a==N-1) {keiyu.at(b)++;}
    if(b==0||b==N-1) {keiyu.at(a)++;}
  }
  rep(i,N){if(keiyu.at(i)==2) {cout<<"POSSIBLE"<<endl; return 0;}}
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}