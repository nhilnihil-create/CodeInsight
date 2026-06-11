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
 ll h,w ;
 cin >> h>> w ;
 ll ans=0 ;
 if(h*w%3==0)
 ans=0 ;
 else{ll k=w/3 ;ll l=h/3 ;
 ll hmi=h/2 ;ll wmi= w/2 ;
 if(h%2==1) hmi= k+(h+1)/2 ;if(w%2==1) wmi =l+(w+1)/2 ;
 ans=min(h,min(w,min(hmi,wmi))) ;
 }
 cout <<ans<<endl ;
     return 0;
}