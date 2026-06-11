#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, M, R;
  cin >> N >> M >> R;

  vector<int> town(R), root(R);
  rep(i, R)
  {
    cin >> town[i];
    town[i]--;
    root[i] = i;
  }
  sort(root.begin(), root.end());

  long long INF = 100000000;
  vector<vector<long long>> d(N, vector<long long>(N, INF));
  rep(i, M)
  {
    int A, B, C;
    cin >> A >> B >> C;
    A--;
    B--;
    d[A][B] = C;
    d[B][A] = C;
  }
  rep(i, N)
  {
    d[i][i] = 0;
  }
  rep(k, N) rep(i, N) rep(j, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  long long ans = INT32_MAX;
  do
  {
    long long cost = 0;
    rep(i, R - 1)
    {
      cost += d[town[root[i]]][town[root[i + 1]]];
    }
    ans = min(ans, cost);
  } while (next_permutation(root.begin(), root.end()));

  cout << ans << endl;
  return 0;
}