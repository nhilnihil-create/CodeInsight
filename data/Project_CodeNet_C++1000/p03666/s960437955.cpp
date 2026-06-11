#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  if (a > b) swap(a, b);
  ll diff = b-a;
  for (ll i = 0; i < n-1; ++i) {
    // ll diff2 = diff+i*d;
    ll diff2 = diff+i*c;
    if (diff2 >= c*(n-1-i) && diff2 <= d*(n-1-i)) {
      cout << "YES" << endl;
      return 0;
    }
    ll diff3 = diff+i*d;
    if (diff3 >= c*(n-1-i) && diff3 <= d*(n-1-i)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
