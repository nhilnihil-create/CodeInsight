#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
vector<vector<int> > G(101010);
vector<int> height(101010);
void dfs(int v) {
  int depth = 0;
  if (G[v].size() == 0) return;
  vector<int> V;
  for (int i = 0; i < G[v].size(); i++) {
    int u = G[v][i];
    dfs(u);
    V.push_back(height[u]);
  }
  sort(V.begin(), V.end(), greater<int> ());

  for (int i = 0; i < G[v].size(); i++) {
    height[v] = max(height[v], V[i] + (i + 1));    
  }
  return;
}

signed main(){
  int N;
  cin >> N;
  for(int i = 2; i <= N; i++) {
    int a;
    cin >> a;
    G[a].push_back(i);
  } 
  dfs(1);
  cout << height[1] << endl;
}
