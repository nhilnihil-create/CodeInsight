#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<(n);++i)
using ll = long long;
template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

main(){

  ll n;
  cin>>n;
  pair<ll,ll> res(0,0);
  rep(i,n){
    pair<ll,ll> a;
    cin>>a.first>>a.second;
    chmax(res,a);
  }
  cout<<(res.first+res.second)<<endl;

}