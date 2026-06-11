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
int main() {
 int  n ;
 cin >> n ;
 vector<int> s(n) ;
 rep(i,n) cin>> s[i] ;
 sort(s.begin(),s.end()) ;
 int ans= 0 ;
 int sum =0 ;
 rep(i,n) sum+= s[i] ;
 if(sum%10!=0) {
   ans=sum ;
 }

 else{
   int hazure=-1 ;
   rep(i,n) if(s[i]%10!=0){
     hazure=s[i] ;
     break ;
   }
 if(hazure==-1) ans=0 ;
 else ans=sum-hazure ;
 
 }
 
 cout <<ans<<endl ;
     return 0;
}