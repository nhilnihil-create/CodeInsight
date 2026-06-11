#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll k;
  const ll n = 50;

  while (cin >> k) {
    ll m = 0;
    if (k > 0) {
      m = (k - 1) / n + 1;
    }

    ll a[n];
    for (int i = 0; i < n; i++) {
      a[i] = (n - 1) + m;
    }

    if (k > 0) {
      ll rem = n - (((k - 1) % n) + 1);
      for (int i = 0; i < rem; i++) {
	a[i] -= (n - rem + 1);
      }
      for (int i = rem; i < n; i++) {
	a[i] += rem;
      }
    }

    cout << n << endl;
    for (int i = 0; i < n; i++) {
      if (i != 0) {
	cout << " ";
      }
      cout << a[i];
    }
    cout << endl;
  }
}
