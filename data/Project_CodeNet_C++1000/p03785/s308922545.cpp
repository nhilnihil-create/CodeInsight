#include <bits/stdc++.h>
#include <bits/stdint-intn.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, c, k;
  std::cin >> n >> c >> k;
  std::vector<int> t(n);
  rep(i, n) std::cin >> t[i];

  sort(t.begin(), t.end());

  int sum = 0;
  int i = 0;
  while (i < n) {
    ++sum;
    int pos = i;
    while (i < n && k >= t[i] - t[pos] && c > i - pos)
      ++i;
  }

  std::cout << sum << std::endl;
  return 0;
}
