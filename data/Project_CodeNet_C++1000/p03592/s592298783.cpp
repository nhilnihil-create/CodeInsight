#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

int main(){
  int n,m,k;cin>>n>>m>>k ;
  bool ok=0 ;
  rep(i,n+1){
    rep(j,m+1){
      if(i*j+(n-i)*(m-j)==k) ok= 1 ;
    }
  }
  if(ok) cout<<"Yes"<<endl ;
  else cout<<"No"<<endl ;
      return 0;
  }
  