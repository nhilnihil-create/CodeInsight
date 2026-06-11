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
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main(){
  ll n,a,b ;
  cin>>n>>a>>b ;
  if(n==1){
    if(a==b) cout <<1<<endl ;
    else cout<<0<<endl ;
  }
    
    else{
      if(a>b) cout<<0<<endl ;
      else cout<<(n-2)*(b-a)+1 <<endl ;
    }
    return 0;
  }