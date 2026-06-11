#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, n) cin >> s.at(i);
  sort(s.begin(), s.end());

  int sum = 0;
  rep(i, n) {
    sum += s.at(i);
  }
  int res = sum;
  int i = 0;
  while (res % 10 == 0 && i < n) {
    if ((res - s.at(i)) % 10 != 0) {
      res -= s.at(i);
    }
    i++;
  }
  if (res == sum && res % 10 == 0) {
    res = 0;
  }
  cout << res << endl;
  return 0;
}
