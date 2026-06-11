#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  if (a == b && b == c && a %2 == 0) {
    cout << -1 << endl;
    return EXIT_SUCCESS;
  }

  ll i;
  for (i = 0; a % 2 == 0 && b % 2 == 0 && c % 2 == 0; ++i) {
    ll a2 = a;
    ll b2 = b;
    ll c2 = c;
    a = (b2 + c2) / 2;
    b = (a2 + c2) / 2;
    c = (a2 + b2) / 2;
  }

  cout << i << endl;
}
