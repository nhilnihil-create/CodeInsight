#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, x;
  cin >> n >> x;
  ll ans = n;
  ll a = n - x, b = x;
  if (a < b) swap(a, b);
  while (b != 0) {
    ans += 2 * (a / b) * b;
    a %= b;
    swap(a, b);
  }
  cout << ans - a << endl;
}