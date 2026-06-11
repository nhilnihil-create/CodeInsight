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
   ll  n , a, b , c,  d ; cin>> n>>a>>b>>c>>d ;
   ll x= abs(a-b ) ; n-- ;
    if(d*n <x ) cout<<"NO"<<endl ;
    else{
      
      bool ok= 0 ;
      rep2(i,0,n){
        ll mi = c*i- d*(n-i) ;
        ll ma = d*i-c*(n-i) ;
        if(mi<=x && x<=ma){
          ok=1 ;
        }
      }
      if(ok) cout<< "YES"<<endl ;
      else cout<< "NO"<<endl ;
      
    }

   return 0 ;
 }

