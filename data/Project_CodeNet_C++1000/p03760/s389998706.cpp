#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

string o, e;

int main() {
  cin >> o >> e;
  rep (i, o.size()+e.size()) {
    if (i % 2 == 0) {
      cout << o[i/2];
    } else {
      cout << e[(i-1)/2];
    }
  }
  cout << endl;
  return 0;
}
