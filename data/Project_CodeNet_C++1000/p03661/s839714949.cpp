#define _GCLIBCXX_DEBUG
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

typedef long long ll;

ll dp[2*100000+7];

int main(int argc, char* argv[])
{
  ll n;
  std::cin >> n;
  std::vector< ll > va(n, 0);

  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    std::cin >> va[i];
    sum += va[i];
  }

  ll ans = 1e10;
  dp[0] = 0;
  for (ll i = 0; i < n-1; i++) {
    dp[i+1] = va[i] + dp[i];
    ans = std::min(ans, (ll)std::fabs(sum - dp[i+1] * 2));
    //std::cout << ans << " " << sum << " " << dp[i+1] << std::endl;
  }

  std::cout << ans << std::endl;
  return 0;
}
