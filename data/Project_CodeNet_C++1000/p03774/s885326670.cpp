#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int ,int>> vec1(n);
  vector<pair<int ,int>> vec2(m);
  for (auto &v : vec1) {
    int a, b;
    cin >> a >> b;
    v = make_pair(a, b);
  }
  for (auto &v : vec2) {
    int c, d;
    cin >> c >> d;
    v = make_pair(c, d);
  }

  for (int i = 0; i < n; ++i) {
    int a = vec1[i].first;
    int b = vec1[i].second;
    int ans = -1;
    int vmin = 1e9;
    for (int j = m - 1; 0 <= j; --j) {
      int c = vec2[j].first;
      int d = vec2[j].second;
      int tmp = abs(a - c) + abs(b - d);
      if (tmp <= vmin) {
        ans = j;
        vmin = tmp;
      }
    }
    cout << ans + 1 << endl;
  }
}
