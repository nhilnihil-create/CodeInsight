//Link : https://atcoder.jp/contests/arc083/tasks/arc083_b
#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define N 305
long long dist[N][N];
long long R[N][N];
vector<int> adj[N];
void sp(int node) {
  R[node][node] = 0;
  priority_queue<pair<long long,int> ,vector<pair<long long,int> >, greater<pair<long long,int> > >pq;
  pq.push(make_pair(0,node));
  while(!pq.empty()) {
    long long d = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    if(d!=R[node][cur]) {
      continue;
    }
    for(int i=0;i<adj[cur].size();++i) {
      int nextNode = adj[cur][i];
      if(R[node][nextNode]==-1 || R[node][nextNode]> d + dist[nextNode][cur]) {
        R[node][nextNode] = d+ dist[nextNode][cur];
        pq.push(make_pair(R[node][nextNode],nextNode));
      }
    }
  }
}
pair<long long,pair<int,int> > in[N*N];
void solve() {
  int n;scanf("%d",&n);
  int pos = 0;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=n;++j) {
      scanf("%lld ", &dist[i][j]);
      if(i<j)
        in[pos++] = (make_pair(dist[i][j],make_pair(i,j)));
    }
  }
  sort(in,in+pos);
  memset(R,-1,sizeof(R));
  long long ret = 0;
  for(int i=0;i<pos;++i) {
    long long d = in[i].first;
    int x = in[i].second.first, y= in[i].second.second;
    bool needEdge = true;
    for(int node=1;node<=n;++node) {
      if(node==x || node==y) {
        continue;
      }
      if(d == dist[x][node] + dist[node][y]) {
        needEdge = false;
      }
    }
    if(needEdge) {
      ret += d;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
  }
  for(int i=1;i<=n;++i) {
    sp(i);
  }
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=n;++j) {
      if(R[i][j]!=dist[i][j]) {
        printf("-1\n");
        return;
      }
    }
  }
  printf("%lld\n", ret);
}
int main() {
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
