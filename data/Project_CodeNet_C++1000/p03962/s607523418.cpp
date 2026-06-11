#include <bits/stdc++.h>
#define rep2(i, n, m) for (int i = m; i < (int)(n); i++)
#define rep(i, n) rep2(i, n, 0)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;  //
template <typename T>
T sq(T x) {
  return x * x;
}
signed main() {
  int a, b, c;
  cin >> a;
  cin >> b;
  cin >> c;
  set<int> Set;
  Set.insert(a);
  Set.insert(b);
  Set.insert(c);
  cout << Set.size() << endl;
  return 0;
}

