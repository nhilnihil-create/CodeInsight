#include <assert.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

// const ll MOD = 998244353;
const ll MOD = 1000000007;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll x, y;
  std::cin >> x >> y;
  if (x < y) std::swap(x, y);
  if (x > y + 1) {
    std::cout << "Alice";
  } else {
    std::cout << "Brown";
  }
  return 0;
}