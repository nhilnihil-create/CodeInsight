#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  int N, P, A;
  cin >> N >> P;
  bool cond = false;
  ll ans{1};
  while (cin >> A) {
    cond |= A % 2;
    ans *= 2;
  }
  if (cond) ans /= 2;
  else if (P) ans = 0;

  cout << ans << endl;
}
