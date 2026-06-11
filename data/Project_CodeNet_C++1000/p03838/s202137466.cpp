#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<int>>; 
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
 ll x,y ; cin>>x>>y ;
 if(x<y&&(y<=0 || 0<= x)) cout<< y-x<<endl ;
 else if(x*y<0) cout<< abs( abs(x)- abs(y))+1 <<endl ;
 else if(x>y&&(0>x || 0<y)) cout<< abs(abs(x)-abs(y))+2 <<endl ;
 else cout<< abs(abs(x)-abs(y)) +1 <<endl ;
  
 return 0 ; 
}

