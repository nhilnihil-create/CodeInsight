#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
#define rep3(i,n,m) for(long long i=n;i>=m;i--)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
 ll n,l ;
 cin>> n>>l ;
 vector<ll> A(n) ;
 rep(i,n) cin>> A[i] ;
 ll ko=-1 ;
 rep(i,n-1){
 if(A[i]+A[i+1]>=l){
   ko= i ;
   break ;
 }
 }
   if(ko==-1)
   cout <<"Impossible"<<endl ;
   else{
    cout<<"Possible"<<endl ;
     rep2(i,1,ko){
       cout<<i<<endl ;
     }
      rep3(i,n-1,ko+2){
        cout <<i<<endl;
      }
       cout <<ko+1<<endl ;
   }
    
    return 0;
}