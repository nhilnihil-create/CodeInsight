#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string A[2];
ll Q;
vector<ll> X[2];

int main() {
  cin >> A[0] >> A[1] >> Q;
  for (ll k : {0, 1}) {
    string &a = A[k];
    vector<ll> &x = X[k];
    x.push_back(0);
    for (char c : a) x.push_back(x.back() + (c == 'A' ? 1 : 2));
  }
  for (ll q = 0; q < Q; ++q) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    --a;
    --c;
    bool ok = abs((X[0][b] - X[0][a]) - (X[1][d] - X[1][c])) % 3 == 0;
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
