#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
#define N 310000
int a[1100];
int main(){
  int n=in(),m=in();
  rep(i,m)a[i]=in();
  if(m==1){
  cout<<n<<endl;
    if(n==1){
    cout<<1<<endl<<1;return 0;}
  cout<<2<<endl;
  cout<<n-1<<" "<<1;return 0;}
  int cnt=0;
  rep(i,m){
  if(a[i]%2){
  cnt++;}}
  if(cnt>2)cout<<"Impossible";
  else{
    int t=0;
    rep(i,m){
      if(t==0&&a[i]%2){
        swap(a[0],a[i]);
        t++;
      }
      else if(a[i]%2)swap(a[m-1],a[i]);
    }
    rep(i,m)cout<<a[i]<<" ";
    cout<<endl<<(a[0]==1?m-1:m)<<endl;
    if(a[0]-1)cout<<a[0]-1<<" ";
    rep2(i,1,m-2)cout<<a[i]<<" ";
    cout<<a[m-1]+1;
  }
}
