#include <algorithm>
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<uint64_t> a(n);
  rep(i, n) std::cin >> a[i];

  std::map<int, int> map;
  rep(i, n) { map[a[i]]++; }

  int num = 0;
  for (auto i : map) {
    if (i.second % 2) {
      num++;
    }
  }

  std::cout << num << std::endl;
  return 0;
}
