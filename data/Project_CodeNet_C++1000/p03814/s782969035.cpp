#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int zMax = 0;
  rep(i, s.size()) {
    if (s.at(i) == 'Z') {
      zMax = max(zMax, i);
    }
  }
  int aMinx = s.find('A');
  cout << zMax - aMinx + 1 << endl;
  return 0;
}
