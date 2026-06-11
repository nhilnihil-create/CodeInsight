#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> g;
vector<vector<int>> gInv;
vector<int> onRoute;

void dfs(int p)
{
  if (onRoute[p])
    return;
  onRoute[p]++;
  for (auto& nxt : g[p])
    dfs(nxt.first);
}

void dfsInv(int p)
{
  if (onRoute[p] == 0 || onRoute[p] == 2)
    return;
  onRoute[p]++;
  for (auto& nxt : gInv[p])
    dfsInv(nxt);
}

int main()
{
  int n, m;
  cin >> n >> m;
  g.resize(n);
  gInv.resize(n);
  rep(i, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    c = -c;
    g[a].emplace_back(b, c);
    gInv[b].push_back(a);
  }
  onRoute.resize(n);
  fill(onRoute.begin(), onRoute.end(), 0);
  dfs(0);
  dfsInv(n - 1);
  vector<ll> score(n, LONG_LONG_MAX);
  score[0] = 0;
  rep(i, n)
    rep(j, n)
    {
      if (onRoute[j] != 2 || score[j] == LONG_LONG_MAX)
        continue;
      for (auto& k : g[j])
      {
        if (onRoute[k.first] != 2)
          continue;
        if (score[k.first] > score[j] + k.second)
        {
          score[k.first] = score[j] + k.second;
          if (i == n - 1)
          {
            cout << "inf\n";
            return 0;
          }
        }
      }
    }
  cout << -score[n - 1] << endl;
  return 0;
}