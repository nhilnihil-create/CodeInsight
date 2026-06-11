#include <bits/stdc++.h>

int main(void)
{
  int K, S;
  std::cin >> K >> S;

  int ans = 0;
  for (int x = 0; x <= K; x++) {
    for (int y = 0; y <= K; y++) {
      int z = S - x - y;

      if (z >= 0 && z <= K) {
        ans++;
      }
    }
  }
  std::cout << ans << std::endl;

  return 0;
}