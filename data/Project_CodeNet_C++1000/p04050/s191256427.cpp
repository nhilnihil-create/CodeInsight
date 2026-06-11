#include <bits/stdc++.h>

void run() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> a[i];
  }
  if (m == 1) {
    std::cout << n << std::endl;
    if (n == 1) {
      std::cout << 1 << std::endl;
      std::cout << 1 << std::endl;
    } else {
      std::cout << 2 << std::endl;
      std::cout << n - 1 << " " << 1 << std::endl;
    }
  } else {
    std::vector<int> odd, even;
    for (auto &&x: a) {
      if (x % 2 == 1) odd.push_back(x);
      else even.push_back(x);
    }
    if (odd.size() > 2) std::cout << "Impossible" << std::endl;
    else {
      a.clear();
      if (odd.size()) a.push_back(odd[0]);
      for (auto &&x: even) a.push_back(x);
      if (odd.size() > 1) a.push_back(odd[1]);
      for (auto &&x: a) std::cout << x << " ";
      std::cout << std::endl;
      a[0]--;
      a.back()++;
      std::vector<int> b;
      for (auto &&x: a) {
        if (x) b.push_back(x);
      }
      std::cout << b.size() << std::endl;
      for (auto &&x: b) std::cout << x << " ";
      std::cout << std::endl;
    }
  }
}

int main() {
  run();
  return 0;
}
