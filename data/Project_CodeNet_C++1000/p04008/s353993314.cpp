#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

pair<int, int> solve(int x, int K, vector<int>& parent,
                     vector<vector<int>>& E) {
  int ret = 0;
  int prev = 0;
  for (int y : E[x]) {
    auto p = solve(y, K, parent, E);
    ret += p.first;
    prev = max(prev, p.second);
  }

  if ((x == 0 || prev == K - 1) && parent[x] != 0) {
    ret++;
    prev = -1;
  }

  prev++;
  return {ret, prev};
}

int main(void) {
  ios_base::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;

  vector<int> parent(N);
  REP(i, N) {
    cin >> parent[i];
    --parent[i];
  }

  if (K == 1) {
    int ret = 0;
    REP(i, N) if (parent[i] != 0) ret++;
    cout << ret << "\n";
    return 0;
  }

  vector<vector<int>> E(N);
  FOR(i, 1, N) E[parent[i]].push_back(i);

  int ret = 0;

  ret += solve(0, K, parent, E).first;

  cout << ret << "\n";
  return 0;
}
