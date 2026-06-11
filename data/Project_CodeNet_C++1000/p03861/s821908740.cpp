#include <iostream>
using namespace std;
typedef long long ll;

ll f(ll n, ll x) {
  if (n == -1) return 0;
  return n / x + 1;
}

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  cout << f(b, x) - f(a - 1, x) << endl;
  return 0;
}