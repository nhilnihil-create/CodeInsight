#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX;
const ll MOD = 1e9+7;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,M;cin>>N>>M;
  vector<vint> g(N);
  repeat(i,M){
    int u,v;cin>>u>>v;u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> visit(N,false);
  vint color(N,0);
  ll dim0=0,bi=0,nobi=0;
  repeat(i,N){
    if(visit[i])continue;
    if(g[i].empty()){
      dim0++;
      continue;
    }
    bool isbi=true;
    queue<int> Q;
    Q.push(i);
    color[i]=1;
    while(!Q.empty()){
      int v = Q.front();
      Q.pop();
      if(visit[v])continue;
      visit[v]=true;
      for(int u:g[v]){
        if(color[v]==color[u])isbi=false;
        color[u]=-color[v];
        Q.push(u);
      }
    }
    if(isbi)bi++;
    else nobi++;
  }
  debugArray(color,N);
  debug(dim0);
  debug(nobi);
  debug(bi);
  cout << dim0*(2*N-dim0)+nobi*nobi+2*nobi*bi+2*bi*bi<<endl;
  return 0;
}
