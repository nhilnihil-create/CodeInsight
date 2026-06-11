#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

int main()
{
  ll N;
  std::cin >> N;
  std::vector< ll > vl(2 * N, 0LL);
  for (ll i = 0; i < 2 * N; i++) {
    std::cin >> vl[i];
  }

  std::sort(vl.begin(), vl.end(), std::less<>());
  ll ans = 0LL;
  for (ll i = 0; i < 2 * N; i+=2) {
    ans += vl[i];
  }

  std::cout << ans << std::endl;
  return 0;
}
