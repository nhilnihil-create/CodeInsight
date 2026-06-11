#include <iostream>

using namespace std;

typedef long long ll;

int main () {
  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  n--; // now the number of moves
  for (int i = 0; i <= n; i++) {
    // number of times we subtract;
    ll mn = a + c * (n - i) - d * i;
    ll mx = a + d * (n - i) - c * i;

    if (mn <= b && b <= mx) {
      cout << "YES" << endl;
      exit(0);
    }
  }

  cout << "NO" << endl;
}
