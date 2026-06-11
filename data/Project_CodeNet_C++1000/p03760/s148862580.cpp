#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  string o, e;
  cin >> o >> e;
  rep(i, min(o.size(), e.size())) { cout << o[i] << e[i]; }
  if (o.size() > e.size()) cout << o[o.size() - 1];
  if (o.size() < e.size()) cout << e[e.size() - 1];
  cout << endl;
  return 0;
}
