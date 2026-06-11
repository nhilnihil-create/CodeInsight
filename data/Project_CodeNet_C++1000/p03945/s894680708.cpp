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
 string s ;
 cin >> s ;
 int k=s.size() ;
 int ans=0 ;
 rep(i,k-1) {
   if(s[i]!=s[i+1] ) ans ++ ;
 }

cout <<ans <<endl ;
     return 0;
}
