#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  rep(i, n) std::cin >> a[i];

  std::set<int> se;

  int wild = 0;
  rep(i, n) {
    if (a[i] >= 3200) {
      wild++;
    } else {
      se.insert(a[i] / 400);
    }
  }

  int maxv = se.size() + wild;
  int minv = 0;
  if (se.size() == 0) {
    minv = 1;
  } else {
    minv = se.size();
  }

  std::cout << minv << " " << maxv << std::endl;

  return 0;
}
