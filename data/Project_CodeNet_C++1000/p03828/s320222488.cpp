#include <iostream>
#include <vector>
#include <map>

std::vector<std::pair<int, int>> prime_factor(long long n) {
  std::vector<std::pair<int, int>> res;
  for (long long p = 2; p * p <= n; ++p) {
    int exp = 0;
    while (n % p == 0) {
      n /= p;
      ++exp;
    }
    if (exp)
      res.push_back(std::make_pair(p, exp));
  }
  if (n != 1)
    res.push_back(std::make_pair(n, 1));
  return res;
}

int main() {
  int mod = 1000000007;

  int n;
  std::cin >> n;

  std::map<int, int> mp;
  for (int i = 1; i <= n; ++i) {
    auto fs = prime_factor(i);
    for (auto &v : fs) {
      mp[v.first] += v.second;
    }
  }

  long long res = 1;
  for (auto &kv : mp)
    res = res * (kv.second + 1) % mod;
  std::cout << res << std::endl;
}
