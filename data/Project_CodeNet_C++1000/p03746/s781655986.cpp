//Link : https://atcoder.jp/contests/agc013/tasks/agc013_b
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define N 100005

vector<int> adj[N];

int ret[N];
int pos = 0;
bool vis[N];
void dfs(int node,bool isRoot) {
  bool isEndNode = true;
  vis[node] = true;
  int cc = 1;
  ret[pos++] = node;
  if(isRoot) {
    cc = 2;
  }
  for(int i=0;i<(int)adj[node].size()&& cc>0;++i) {
    int ch = adj[node][i];
    if(vis[ch]) {
      continue;
    }
    dfs(ch,0);
    --cc;
    if(isRoot) {
      reverse(ret,ret+pos);
    }
  }
}
void solve() {
  int n,m; scanf("%d %d ", &n,&m);
  for(int i=0;i<m;++i) {
    int a,b;scanf("%d %d ", &a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,1);
  printf("%d\n", pos);
  for(int i=0;i<pos;++i) {
    printf("%d ", ret[i]);
  }
  putchar('\n');
}
int main() {
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
