#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;

  int ans = 1;
  while(ans <= n) {
    ans *= 2;
  }

  std::cout << ans / 2 << std::endl;
  return 0;
}
