#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  if (n <= 6) {
    cout << 1 << endl;
  } else {
    if (n % 11 == 0) {
      cout << 2 * (n / 11) << endl;
    } else if (n % 11 <= 6) {
      cout << 2 * (n / 11) + 1 << endl;
    } else {
      cout << 2 * (n / 11) + 2 << endl;
    }
  }
  return 0;
}