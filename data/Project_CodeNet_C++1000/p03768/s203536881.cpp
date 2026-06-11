#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef pair<int,int> P;
 
int main(){
  int n, m, q;
  cin >> n >> m;
  vector<int> g[n];
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin >> q;
  vector<int> v(q), d(q), c(q);
  rep(i,q) {
    cin >> v[i] >> d[i] >> c[i];
    v[i]--;
  }
  reverse(v.begin(),v.end());
  reverse(d.begin(),d.end());
  reverse(c.begin(),c.end());
  
  vector<int> color(n,0);
  vector<int> dist(n,-1);
 
  rep(i,q){
    queue<P> que;
    que.push(P(v[i],d[i]));
    while(!que.empty()){
      P p = que.front();
      que.pop();
      if(color[p.first] == 0) color[p.first] = c[i];
      dist[p.first] = p.second;
      rep(j,g[p.first].size()){
        if(p.second-1 > dist[g[p.first][j]]) {
          que.push(P(g[p.first][j],p.second-1));
        }
      }
    }
  }
  rep(i,n) cout << color[i] << endl;
  return 0;
}