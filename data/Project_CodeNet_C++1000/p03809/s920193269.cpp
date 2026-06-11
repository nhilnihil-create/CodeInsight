#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using Graph = vector<vector<int>>;
int n;
vector<ll> a(100000), c(100000, -1);
bool f = true;

ll dfs(const Graph &g, int cur, int pre)
{
  int sz = g[cur].size();
  if (pre != -1 && sz == 1)
  {
    // leaf
    return c[cur] = a[cur];
  }
  ll sum = 0;
  vector<int> v;
  for (int i = 0; i < sz; i++)
  {
    int next = g[cur][i];
    if (next == pre)
      continue;
    sum += dfs(g, next, cur);
    v.push_back(next);
  }
  c[cur] = 2 * a[cur] - sum;
  if (c[cur] < 0 || c[cur] > a[cur])
  {
    f = false;
  }
  if ((sum - c[cur]) % 2 || sum - c[cur] < 0)
  {
    f = false;
  }
  ll num = (sum - c[cur]) / 2; // num 組作れるか
  ll cnt = 0;
  for (int i = 0; i < sz; i++)
  {
    int next = g[cur][i];
    if (next == pre)
      continue;
    if (c[next] > num)
    {
      cnt += c[next] - num;
    }
  }
  if (cnt > c[cur])
    f = false;
  return c[cur];
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  Graph g(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++)
  {
    int st, gt;
    cin >> st >> gt;
    st--;
    gt--;
    g[st].push_back(gt);
    g[gt].push_back(st);
  }
  if (n == 2)
  {
    if (a[0] == a[1])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return 0;
  }
  dfs(g, 0, -1);
  if (g[0].size() > 1 && c[0] != 0)
  {
    f = false;
  }
  if (g[0].size() == 1 && c[0] != a[0])
  {
    f = false;
  }
  if (f)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
