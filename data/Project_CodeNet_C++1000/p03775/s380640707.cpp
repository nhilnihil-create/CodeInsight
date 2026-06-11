#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;

int nod(ll n) {
  int c = 0;
  while (n) n /= 10, c++;
  return c;
}

int f(ll a, ll b) {
  return max(nod(a), nod(b));
}

int main() {
  ll n;
  cin >> n;
  int ans = f(n, 1);
  for (ll i = 2; i*i <= n; i++) {
    if (n % i == 0) {
      ans = min(ans, f(i, n/i));
    }
  }
  cout << ans << endl;
}
