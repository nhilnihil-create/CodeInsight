#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> d(k);
  rep(i, k) cin >> d[i];

  auto ok = [&](ll x) {
    bool flag = true;
    while (x > 0) {
      rep(i, k) flag &= (x % 10) != d[i];
      x /= 10;
    }
    return flag;
  };

  while (!ok(n)) n++;

  cout << n << endl;
  return 0;
}
