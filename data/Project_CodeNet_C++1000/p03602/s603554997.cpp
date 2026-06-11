#include<bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9+7;

struct edge {
  int t, w;
  edge(int t, int w) : t(t), w(w) {}
};

int in[301][301], n;
long long dist[301];
vector<tuple<int,int,int>> eg;
vector<edge> g[301];

int foo(int f, int t) {
  for(int i=0;i<n;i++) dist[i] = inf;
  dist[f] = 0;
  priority_queue<pair<int,int>> pq;
  pq.emplace(0,f);
  while(!pq.empty()) {
    int w, c;
    tie(w,c) = pq.top();
    pq.pop();
    w=-w;
    if(w > dist[c]) continue;
    for(auto & e : g[c]) {
      int ww = w + e.w;
      if(ww >= dist[e.t]) continue;
      dist[e.t] = ww;
      pq.emplace(-ww,e.t);
    }
  }
  return dist[t];
}

int main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%d",in[i]+j);
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++) {
        int tmp = in[i][k] + in[k][j];
        if(tmp < in[i][j]) {
          puts("-1");
          return 0;
        }
      }
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      eg.emplace_back(in[i][j],i,j);
  sort(eg.begin(), eg.end());

  long long ans = 0;
  for(auto & e : eg) {
    int w,a,b;
    tie(w,a,b) = e;
    int d = foo(a,b);
    if(d == w) continue;
    ans += w;
    g[a].push_back(edge(b,w));
    g[b].push_back(edge(a,w));
  }
  printf("%lld\n",ans);
}
