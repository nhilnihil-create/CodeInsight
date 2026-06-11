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
 ll n ;cin>> n ;
 string s ;cin>>s ;
 ll gap=0 ; ll ans=0 ;
 rep(i,n){
  if(s[i]==')') gap++ ;
  else gap-- ;
  chmax(ans,gap) ;
 }
 string bns= "";
 {
     rep(i,ans){
         bns+= '(' ;
     }
     bns+=s ;
     rep(i,ans-gap){
         bns+=')' ;
     }
     cout<<bns<<endl ;
 }
 

 
 return 0 ; 
}