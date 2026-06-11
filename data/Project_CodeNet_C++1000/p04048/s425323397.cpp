#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Mod = 1000000007;
int main() {
  ll N,X;
  cin >> N >> X;
  ll a = min(X,N-X);
  ll b = max(X,N-X);
  ll ans = N;
  ans += (b/a) * 2 * a;
  while (b % a != 0) {
    ll c = b % a;
    b = a;
    a = c;
    ans += ((b/a) * 2 * a);
    if (b % a == 0) {
      break;
    }
  }
  ans -= a;
  cout << ans << endl;
  return 0;
}