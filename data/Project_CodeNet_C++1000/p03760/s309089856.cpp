#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string o, e;
  cin >> o >> e;
  rep(i, o.size() + e.size()) {
    if (i % 2 == 0) {
      cout << o[i / 2];
    }
    else {
      cout << e[i / 2];
    }
  }
  cout << endl;
  return 0;
}