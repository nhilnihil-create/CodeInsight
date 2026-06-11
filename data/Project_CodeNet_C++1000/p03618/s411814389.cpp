#include <bits/stdc++.h>

using namespace std;
using i32 = std::int_fast32_t;
using u64 = std::uint_fast64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  u64 N = static_cast<u64>(S.size());
  vector<u64> cnt(26, 0);
  for (i32 i = 0; i < static_cast<i32>(N); i++) {
    cnt[S[i] - 'a']++;
  }
  u64 res = N * (N - 1) / 2;
  for (i32 i = 0; i < 26; i++) {
    res -= cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << res + 1 << '\n';
  return 0;
}
