#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> island(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    island[a].push_back(b);
    island[b].push_back(a);
  }
  for (int i = 0; i < island[0].size(); i++) {
    for (int j = 0; j < island[island[0][i]].size(); j++) {
      if (island[island[0][i]][j] == n - 1) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}