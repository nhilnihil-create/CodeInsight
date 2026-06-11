#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int x, y;
  cin >> x >> y;

  vector<vector<int>> v = {{1, 3, 5, 7, 8, 10 , 12},
  {4, 6, 9, 11},
  {2}};

  int xg, yg;
  rep(j, v.size()) {
    rep(i, v[j].size()) {
      if (v[j][i] == x) xg = j;
      if (v[j][i] == y) yg = j;
    }
  }

  if (xg == yg) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}