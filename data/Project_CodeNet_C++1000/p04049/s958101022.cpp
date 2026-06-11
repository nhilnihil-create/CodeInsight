#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 2000;
int dp[1 + nmax][1 + nmax];
int sz[1 + nmax], dp2[1 + nmax];
vector<int> g[1 + nmax];
int n, k;

int finalresult = nmax;

void dfs(int node, int parent){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }

  sz[node] = 1;
  dp[node][0] = 0;
  for(int i = 0; i <= nmax; i++)
    dp2[i] = nmax;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
    for(int i = 0; i <= sz[node]; i++)
      for(int j = 0; j <= sz[to]; j++)
        if(i + j <= k)
          dp2[max(i, j)] = min(dp2[max(i, j)], dp[node][i] + dp[to][j]);
    sz[node] += sz[to];
    for(int i = 0; i <= sz[node]; i++) {
      dp[node][i] = dp2[i];
      dp2[i] = nmax;
    }
  }

  for(int i = 0;i <= k; i++)
    finalresult = min(finalresult, dp[node][i] + n - (sz[node]));

  for(int i = sz[node]; 0 < i; i--)
    dp[node][i] = dp[node][i - 1];
  dp[node][0] = sz[node];
  if(node != 1)
    dp[node][k + 1] = sz[node];
}

int main()
{
  cin >> n >> k;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 0;i <= n; i++)
    for(int j = 0;j <= n; j++)
      dp[i][j] = n;
  dfs(1, 0);

  cout << finalresult;
  return 0;
}
