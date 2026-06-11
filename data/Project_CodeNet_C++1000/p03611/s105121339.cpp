#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  rep(i, n) std::cin >> a[i];
  std::map<int, int> map;

  rep(i, n) {
    map[a[i] - 1]++;
    map[a[i]]++;
    map[a[i] + 1]++;
  }

  int maxv = 0;
  for (int i = -1; i <= 100001; i++) {
    maxv = max(map[i], maxv);
  }

  std::cout << maxv << std::endl;

  return 0;
}
