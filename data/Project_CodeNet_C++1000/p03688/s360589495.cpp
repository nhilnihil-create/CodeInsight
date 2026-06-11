#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
#define rep3(i,n,m) for(long long i=n;i>=m;i--)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using graph= vector<vector<int>>; 
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main(){
 ll n;
 cin >> n ;
 vector<ll> A(n) ;
 rep(i,n) cin>> A[i] ;
 sort(A.begin(),A.end()) ;
 int sakai=0 ;
 int ans=0 ;
 if(A[0]==A[n-1]){
   if(A[0]==n-1||(A[0])*2<=n)
   ans=1 ;
 }

if(A[0]+1==A[n-1]){
 rep(i,n-1){
   if(A[i]!=A[i+1]){
     sakai =i+1 ;
     break ;
   }
} 
    ll k=A[n-1]-sakai ;
    if(0<k&& 2*k<=(n-sakai))
    ans =1 ;
}
   if(ans==1)
   cout <<"Yes"<<endl ;
   else 
    cout <<"No"<<endl;
    return 0;
}