#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m), b(m);
  rep(i, m) std::cin >> a[i] >> b[i];
  std::map<int, int> map;

  rep(i, m) {
    if (b[i] == n) {
      map[a[i]]++;
    }
  }

  rep(i, m) {
    if (a[i] == 1 && map[b[i]] > 0) {
      std::cout << "POSSIBLE" << std::endl;
      return 0;
    }
  }

  std::cout << "IMPOSSIBLE" << std::endl;
  return 0;
}
