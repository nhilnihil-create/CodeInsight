#include <iostream>
#include <vector>

int main() {
  using std::vector;
  constexpr int inf = 1e9;
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> d(n, vector<int>(n, inf));
  for (int i = 0; i < n; i++) {
    d.at(i).at(i) = 0;
  }
  vector<int> a(m), b(m), c(m);
  for (int i = 0; i < m; i++) {
    std::cin >> a.at(i) >> b.at(i) >> c.at(i);
    a.at(i)--; b.at(i)--;
    d.at(a.at(i)).at(b.at(i)) = c.at(i);
    d.at(b.at(i)).at(a.at(i)) = c.at(i);
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d.at(i).at(j) = std::min(d.at(i).at(j), d.at(i).at(k) + d.at(k).at(j));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (d.at(a.at(i)).at(b.at(i)) < c.at(i)) {
      ans++;
    }
  }
  std::cout << ans << std::endl;
}
