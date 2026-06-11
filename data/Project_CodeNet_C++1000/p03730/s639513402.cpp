#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  if (A == 1) {
    cout << "YES" << endl;
    return 0;
  }

  for (int i = A; i <= (A * B) * 2; i += A) {
    if (i % B == C) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
