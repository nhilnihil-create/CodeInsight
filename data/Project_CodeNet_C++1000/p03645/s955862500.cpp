#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;  cin >> n >> m;
  vector<vector<int>> g(n+1);
  while(m--){
    int a, b;  cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> dist(n+1, 1e9);  dist[1] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
  pque.push({0, 1});
  while(!pque.empty()){
    auto now = pque.top();  pque.pop();
    if(dist[now.second] < now.first)  continue;
    for(auto next : g[now.second])
      if(now.first + 1 < dist[next]){
	dist[next] = now.first + 1;
	pque.push({dist[next], next});
      }
  }

  printf("%s\n", dist[n]<=2 ? "POSSIBLE" : "IMPOSSIBLE");

  return 0;
}
  
