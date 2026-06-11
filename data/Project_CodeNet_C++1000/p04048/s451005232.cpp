#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N, X; cin >> N >> X;
  ll a = N-X;
  ll b = X;
  ll res = N;
  while (a > 0 && b > 0) {
    if (a > b && a % b > 0) {
      res += (a/b)*2*b;
      a %= b;
    }
    if (a >= b && a % b == 0) {
      res += (a/b)*2*b;
      res -= b;
      a = 0; break;
    }
    if (a < b && b % a > 0) {
      res += (b/a)*2*a;
      b %= a;
    }
    if (b > a && b % a == 0) {
      res += (b/a)*2*a;
      res -= a;
      b = 0; break;
    }
  }
  cout << res << endl;
}