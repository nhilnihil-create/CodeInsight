#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<ll>>;
struct edge{ll to ; ll cost ;} ;
using graph =vector<vector<edge>> ;
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second 
#define set20 cout<<fixed<<setprecision(20) ;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
double pi=acos(-1) ;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
 

 int main(){
  ll n ; cin>> n ;
  string t ; cin>> t ;
  vector<ll> s(n) ;
  rep(i,n){
    if(t[i]=='o') s[i]=1 ;
    else s[i]=0 ;
  }
  int ans[n] ;
  bool ok=1 ;
  bool ko=0 ;
  rep(i,2){
    if(ko) break ;
    ans[0]=i ;
    rep(j,2){
      ans[1]=j ;
      int ss= s[0] ;
      ans[2]= (abs(i+j-ss))%2 ;
      int now=3 ;
      int mow=1 ;
      rep(ww,n-3){
        int qq= s[mow] ;
        ans[now]=(abs(ans[now-1]+ans[now-2]-qq))%2 ;
        now++ ;
        mow++ ;
      }

      if((s[n-2]==(ans[0]+ans[n-2]+ans[n-1])%2)&&
          (s[n-1]==(ans[0]+ans[1]+ans[n-1])%2)){
            ok=0 ;
            ko=1 ;
            break ;
          }
    }
  }

  if(ok) cout<<-1<<endl ;
  else{
    rep(i,n-1){
     if(ans[i+1]==1)  cout<<'S' ;
     else cout<< 'W' ;
    }
    if(ans[0]==1) cout<<'S'<<endl ;
    else cout<<'W'<<endl ;
  }
   return 0 ;
 }

