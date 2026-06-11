#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

std::map<long long, int> prime_factor(long long n) {
  std::map<long long, int> res;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) {
    res[n] = 1;
  }
  return res;
}

int main() {
  const int mod = 1000000000 + 7;
  int n;
  cin >> n;

  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    auto m = prime_factor(i);
    for (auto it = m.begin(); it != m.end(); it++) {
      mp[it->first] += it->second;
    }
  }

  long long ans = 1;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    ans *= (it->second + 1);
    ans %= mod;
  }
  cout << ans << endl;

  return 0;
}