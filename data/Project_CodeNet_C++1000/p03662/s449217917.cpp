#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> adj;
const int N = 100001;
int depth[N];
int par[N];
int sz[N];
void dfs(int u, int p = -1){
  depth[u] = p == -1 ? 0 : depth[p] + 1;
  par[u] = p;
  sz[u] = 1;
  for(auto el : adj[u]){
    if(el != p){
      dfs(el, u);
      sz[u] += sz[el];
    }
  }

}
int main(){
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n;
  cin >> n;
  adj.resize(n);
  for(int i = 0;i < n - 1;i++){
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
//  return 0;
  int d = depth[n - 1];
  int v = n - 1;
  for(int i = 0;i < (d - 1) / 2;i++)
    v = par[v];
  if(sz[v] >= sz[0] - sz[v]){
    cout << "Snuke";
  }else{
    cout << "Fennec";
  }
}
