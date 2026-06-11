#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <stack>

typedef long long ll;

int main(int argc, char* argv[])
{
  ll X;
  std::cin >> X;

  ll ans = 0;
  for (int i = 1; i <= X; i++) {
    ll pos = i * (i+1) / 2;
    if (pos >= X) {
      ans = i;
      break;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
