#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, M, R, INF = (1LL << 60), a, b, c, ans = INF;
  cin >> N >> M >> R;
  vector<int64_t> rs(R);
  for (int i = 0; i < R; i++)
  {
    cin >> rs[i];
    rs[i]--;
  }
  vector<vector<int64_t>> path(210, vector<int64_t>(210, INF));
  for (int i = 0; i < N; i++)
  {
    path[i][i] = 0;
  }
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b >> c;
    a--;
    b--;
    path[a][b] = c;
    path[b][a] = c;
  }
  for (int k = 0; k < N; k++)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
      }
    }
  }
  sort(rs.begin(), rs.end());
  do
  {
    int64_t prev = rs[0], tmp = 0;
    for (int i = 1; i < R; i++)
    {
      tmp += path[prev][rs[i]];
      prev = rs[i];
    }
    ans = min(ans, tmp);
  } while (next_permutation(rs.begin(), rs.end()));
  cout << ans << endl;
}