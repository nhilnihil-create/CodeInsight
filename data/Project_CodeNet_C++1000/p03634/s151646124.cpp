#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

vector<P> to[100005];
vector<ll> dist(100005,-1);

void dfs(int v,int p = -1){
  if(p==-1)dist[v]=0;
  for(auto P:to[v]){
    int u = P.first;
    if(u==p)continue;
    dist[u]=dist[v]+P.second;
    dfs(u,v);
  }
}

int main(){
  int n;
  cin >> n;
  rep(i,n-1){
    int a,b,c;
    cin >> a >> b >> c;
    a--,b--;
    to[a].emplace_back(b,c);
    to[b].emplace_back(a,c);
  }
  int q,k;
  cin >> q >> k;
  dfs(k-1);
  rep(i,q){
    int x,y;
    cin >> x >> y;
    cout << dist[x-1]+dist[y-1] << endl;
  }
}