#include <iostream>
#include <cmath>

const long long div_num = 1000000007;

int main() {
  int n, ans = 1;
  std::cin >> n;
  int dist[100000], a[100000];
  bool isContradict = false;

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    dist[a[i]]++;
    // dist[i] = abs((n - 1 - i) - i);
    // std::cout << dist[i] << " ";
    if (n % 2 == 0 && a[i] % 2 != 1) {
      isContradict = true;
    }
    if (n % 2 == 1 && a[i] % 2 != 0) {
      isContradict = true;
    }
  }

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (n % 2 == 0 && dist[i] > 0) {
        isContradict = true;
      } else if (n % 2 == 1 && dist[i] != 1) {
        isContradict = true;
      }
    } else {
      if (n % 2 == 0 && i % 2 == 1 && dist[i] != 2) {
        isContradict = true;
      } else if (n % 2 == 1 && i % 2 == 0 && dist[i] != 2) {
        isContradict = true;
      }
    }
  }

  if (!isContradict) {
    for (int i = 0; i < n / 2; i++) {
      ans *= 2;
      ans %= div_num;
    }
    std::cout << ans << "\n";
  } else {
    std::cout << 0 << "\n";
  }
  return 0;
}