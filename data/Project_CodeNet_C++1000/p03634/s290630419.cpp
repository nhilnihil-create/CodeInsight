#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<functional>
#include<limits.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#include<set>
#include<climits>
#include<bitset>
using namespace std;

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define pb(b) push_back(b) 
#define all(a) a.begin(),a.end()
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define llpvec vector<pair<ll,ll>>
#define size_(a,b) (a,vector<ll>(b))
#define S 21
llfor;////////////////////////////////////////////////////////////
vector<ll>dis(100000,1e18);
void dfs(ll a,vector<vector<pair<ll,ll>>> &path){ 
 for(int i=0;i<path[a].size();++i){
  ll x=path[a][i].first;
  ll y=path[a][i].second;
  if(dis[x]!=1e18)continue;
  dis[x]=dis[a]+y;
  //cout<<a<<" "<<x<<" "<<dis[x]<<endl;
  dfs(x,path);
 }
}

int main(){
 ll n;
 cin>>n;
 ll a,b,c;
 vector<vector<pair<ll,ll>>>path(n);
 dis.resize(n,1e18);
 rep(i,0,n-1){
  cin>>a>>b>>c;
  a--;b--;
  path[a].pb(make_pair(b,c));
  path[b].pb(make_pair(a,c));
 }
 ll q,k;
 cin>>q>>k;
 k--;
 dis[k]=0;
 dfs(k,path);

// pnn;rep(i,0,n)cout<<i<<" "<<dis[i]<<endl;pnn;
 rep(i,0,q){
  cin>>a>>b;
  a--;b--;
  ll ans=dis[a]+dis[b];
  pr(ans);
 }
return 0;}