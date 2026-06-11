#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll N,K; cin>>N>>K;
  vector<ll> list(100001,0);
  rep(i,N){
    ll a,b; cin>>a>>b;
    list.at(a)+=b;
  }
  
  ll sum=0;
  rep(i,100001){
    sum+=list.at(i);
    if(sum>=K) {cout<<i<<endl; return 0;}
  }
  return 0;
}
