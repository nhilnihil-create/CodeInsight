#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);

  int a, b;
  REP(i, M) {
    cin >> a >> b;
    --a;
    --b;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }

  vector<int> d(N, 0);
  vector<bool> visit(N, false);
  queue<int> q;
  q.push(0);
  visit.at(0) = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int const &nv : G.at(v)) {
      if (!visit.at(nv)) {
        q.push(nv);
        visit.at(nv) = true;
        d.at(nv) = d.at(v) + 1;
      }
    }
  }

  if (visit.at(N - 1) && d.at(N - 1) == 2) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
