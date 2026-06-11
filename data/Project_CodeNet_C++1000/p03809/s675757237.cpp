#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
using namespace std;

vector<int> A;
vector<vector<int>> g;

bool dfs(int p, int x, int& r)
{
  vector<int> l;
  int t;
  r = A[x];
  int sum = 0;
  for (auto a : g[x]) {
    if (a == p) continue;
    if (!dfs(x, a, t)) return false;
    l.push_back(t);
    sum += t;
  }
  if (l.size() == 0) return true;
  sort(l.begin(), l.end());
  int mi = sum - min(sum / 2, (sum - l.back()));
  r = 2 * A[x] - sum;
  return mi <= A[x] && A[x] <= sum && r <= A[x];
}

signed main()
{
  int N;
  cin >> N;
  A.resize(N);
  rep(i, N) cin >> A[i];
  g.resize(N, vector<int>());
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int res;
  if (dfs(-1, 0, res) && dfs(-1, N-1, res)) {
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
}
