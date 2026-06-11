#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g[100005];
int in[100005];
int n;
int ans[100005];


void dfs(int v, int prev) {
  vector<int> tmp;
  for(int i = 0; i < g[v].size(); i++) {
    int u = g[v][i];
    if(u == prev) continue;
    dfs(u,v);
    tmp.push_back(ans[u]);
  }
  sort(tmp.begin(),tmp.end(),greater<int> ());
  for(int i = 0; i < tmp.size(); i++) {
    ans[v] = max(ans[v],tmp[i] + i + 1);
  }
 
  return;
}
  
int main() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a;
    cin >> a;
    a--;
    g[a].push_back(i);
    in[a]++;
  }

  dfs(0,-1);
  

 

  // for(int i = 0; i < n; i++) cout << ans[i] << endl;
  cout << ans[0] << endl;
}

  

  

  
  
