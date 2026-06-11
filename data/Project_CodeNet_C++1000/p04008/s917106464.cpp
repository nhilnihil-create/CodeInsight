#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5; 
vector<int> adj[N]; 
int n, k, a[N], ans; 

int dfs(int u) {
  int ret = 0; 
  for(int v : adj[u]) {
    int x = dfs(v); 
    if(x == k - 1 && u != 1) ++ans; 
    else ret = max(ret, 1 + x); 
  } 
  return ret;
}


int main() {
  scanf("%d %d %d", &n, &k, &a[1]);
  for(int i = 2; i <= n; ++i) {
    scanf("%d", &a[i]); 
    adj[a[i]].push_back(i); 
  }

  ans = a[1] != 1; 
  dfs(1); 

  printf("%d\n", ans);
}