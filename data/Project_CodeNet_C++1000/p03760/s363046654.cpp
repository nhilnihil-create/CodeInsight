#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  string O, E;
  cin >> O >> E;
  bool eq = O.size() == E.size();
  int mi = min(O.size(), E.size());

  rep(i, 0, mi) {
    cout << O[i];
    cout << E[i];
  }

  if (!eq) cout << O[O.size() - 1];
  cout << endl;

  return 0;
}
