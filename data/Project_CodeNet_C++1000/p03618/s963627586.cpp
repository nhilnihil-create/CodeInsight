#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  long long ans = 1LL * n * (n + 1) / 2;
  std::vector<int> cnt(26, 0);
  for (int i = 0; i < n; ++i) cnt[s[i] - 'a']++;
  for (int i = 0; i < 26; ++i) ans -= 1LL * cnt[i] * (cnt[i] + 1) / 2;
  std::cout << ans + 1 << "\n";
  return 0;
}
