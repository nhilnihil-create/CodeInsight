#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<string> S(2);
  for (int i = 0; i < 2; i++)
    cin >> S[i];

  int res = 1, pos = 0;
  bool prev;
  if (S[0][0] == S[1][0]) {
    res = 3LL * res;
    pos++;
    prev = true;
  } else {
    res = 6LL * res;
    pos += 2;
    prev = false;
  }

  while (pos < N) {
    if (S[0][pos] == S[1][pos]) {
      if (prev) res = 2LL * res % MOD;
      prev = true;
      pos++;
    } else {
      if (prev)
        res = 2LL * res % MOD;
      else
        res = 3LL * res % MOD;
      prev = false;
      pos += 2;
    }
  }
  cout << res << '\n';
  return 0;
}
