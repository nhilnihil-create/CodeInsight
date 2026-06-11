#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for(ll i=0;i<n;i++) 
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main(){
  string s ;
  cin>> s ;
  ll k=s.size() ;
  
  for(ll i=0 ;2*i<k;i++){
    if(2*i==k-2||2*i==k-1) {
      cout<<s[2*i]<<endl ;
      }else {
        cout<<s[2*i] ;
      }
  }
 
  return 0;
  }