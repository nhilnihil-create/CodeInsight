#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
ll  vo[100005] ; //両方かっこの中箱番号
ll seigo[100005] ;//入っている可能性があるかどうか
int main(){
 ll n,m ; 
 cin>> n>> m;
 vector<ll> A(m) ;
 vector<ll> B(m) ;
 rep(i,m){
   cin>>A[i] >>B[i] ;
   A[i] --;B[i] -- ;
 }
 rep(i,n) vo[i] =1 ;
 seigo[0] = 1 ;
 rep(i,m){
   vo[A[i]]-- ;
   vo[B[i]] ++ ;
   if(seigo[A[i]]==1)
   seigo[B[i]]=1 ;
   if(vo[A[i]]==0)
   seigo[A[i]] =0 ;
 }
 ll ans= 0;
 rep(i,n){
   if(seigo[i]==1) 
   ans++ ;
 }
   
   cout <<ans <<endl ;

   return 0;
}