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
   int H,W ; cin>>H>>W ;
   int h, w ; cin>>h>>w ;
   if(H%h==0&&W%w==0) cout<<"No"<<endl ;
   else{
     cout<<"Yes"<<endl ;
     if(H%h!=0){
       ll a= H%h ; ll b= h-a ;
       ll c= -(a*1000+1) ;
       rep(i,H){
         rep(j,W){
           ll ans ;
           ll p= i%h ;
           if(p<a) ans=1000 ;
           else if(p==h-1) ans = c ;
           else ans =0 ;
           if(j==W-1) cout<<ans<<endl ;
           else cout<<ans<<" " ;
         }
       }

     }

     else{
       ll a= W%w ; ll b= w- a ;
       ll c= -(a*1000+1) ;
       rep(i,H){
         rep(j,W){
           int ans  ;
           ll p = j%w ;
          if(p<a) ans = 1000 ;
          else if(p==w-1) ans = c ;
          else ans=0 ;
          if(j==W-1) cout<<ans<<endl ;
          else cout<<ans<<" " ;
         }
       }
     }
   }
   return 0 ;
 }

