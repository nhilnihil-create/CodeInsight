#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll c = 1000000007;

ll kaijo(ll n) {
  if (n == 1)
    return 1;
  else
    return n * kaijo(n - 1) % c;
}

int main() {
  ll n, m;
  cin >> n >> m;
  ll ans = (kaijo(n) * kaijo(m)) % c;
  if (n == m)
    cout << (ans * 2) % c << endl;
  else if (abs(n - m) == 1)
    cout << ans << endl;
  else
    cout << 0 << endl;
  return 0;
}