#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, M;
  int INF = 1e7;
  cin >> N >> M;
  vector<vector<int>> d(N, vector<int>(N, INF));
  vector<array<int, 3>> edge(M);
  vector<bool> is_used(M, false);

  rep(i, M)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    d[a][b] = c;
    d[b][a] = c;
    edge[i] = {a, b, c};
  }
  rep(i, N)
  {
    d[i][i] = 0;
  }
  rep(k, N) rep(i, N) rep(j, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  rep(i, M)
  {
    int a = edge[i][0];
    int b = edge[i][1];
    int c = edge[i][2];
    rep(s, N) rep(e, N)
    {
      if (d[s][a] + c + d[b][e] == d[s][e] || d[s][b] + c + d[a][e] == d[s][e])
      {
        is_used[i] = true;
      }
    }
  }
  int ans = 0;
  rep(i, M)
  {
    if (!is_used[i])
      ans++;
  }
  cout << ans << endl;
  return 0;
}