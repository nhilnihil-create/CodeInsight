#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll m = 1e9 + 7;
ll powmod(ll b, ll p, ll m) {
  if (p == 0)
    return 1;
  if (p % 2 == 1)
    return b * powmod(b, p - 1, m) % m;
  else {
    ll t = powmod(b, p / 2, m);
    return t * t % m;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> diff(n, 0);
  bool valid = 1;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    diff[temp] += 1;
  }

  for (int i = (n % 2 == 0); i < n; i += 2) {
    if (diff[i] != (1 + (i > 0))) {
      valid = 0;
      break;
    }
  }

  if (valid)
    cout << powmod(2, n / 2, m) << endl;
  else
    cout << 0 << endl;
}
