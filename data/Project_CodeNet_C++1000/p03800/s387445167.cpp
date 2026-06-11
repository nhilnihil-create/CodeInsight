#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  s += s;

  vector<int> res(n + 2);

  auto test = [&](int a, int b) {
    res[0] = a;
    res[1] = b;
    for (int i = 2; i < n + 2; i++) {
      res[i] = res[i - 2];
      if (s[i - 1] == 'x') res[i] ^= 1;
      if (res[i - 1] == false) res[i] ^= 1;
    }
    return (res[0] == res[n] && res[1] == res[n + 1]);
  };

  for (auto a : {0, 1}) {
    for (auto b : {0, 1}) {
      if (test(a, b)) {
        for (int i = 0; i < n; i++) {
          cout << (res[i] ? 'S' : 'W');
        }
        cout << '\n';
        return 0;
      }
    }
  }

  cout << -1 << '\n';
  return 0;
}
