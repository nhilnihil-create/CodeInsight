#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define REP(i, n) for (LL i = 0; i < (LL)(n); i++)
#define REP2(i, n) for (LL i = 1; i <= (LL)(n); i++)
#define FOR(i, m, n) for (LL i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REVE(x) reverse(x.begin(), x.end())
#define ALL(x) (x).begin(), (x).end()
#define SUM(x) accumulate(x.begin(), x.end(),0)
#define vLL(v,n) vector<LL> v(n); REP(i,n)cin>>v[i];
#define vstr(v,n) vector<string> v(n); REP(i,n)REP(i,n)cin>>v[i];
LL INF = 1e9 + 1;
LL MOD = 1e9+7;
  LL a,b,c,d,e,n,m,l,k,r,x,y,z,t,ans=INF,ans2=0,p;
  bool flag=false;
string s,S;
int main() {
ios_base::sync_with_stdio(false);
char str [222];
scanf ("%s", str ) ;
int n= strlen (str ) ;
for (int i=n -2; i; i -=2) {
  if( strncmp (str , str +i/2 , i/2) ==0) {
     printf ("%d\n" ,i) ;
     return 0;
  }
}
return 0;
}