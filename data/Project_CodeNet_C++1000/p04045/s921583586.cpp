#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

bool isOk(int x, vector<bool> ngs) {
  string xx = to_string(x);
  for (char c : xx) {
    if (ngs.at(c - '0')) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> d(k);
  rep(i, k) cin >> d.at(i);
  vector<bool> ngs(10, false);
  rep(i, k) {
    int ngi = d.at(i);
    ngs.at(ngi) = true;
  }
  int res = n;
  while (!isOk(res, ngs)) {
    res++;
  }
  cout << res << endl;
  return 0;
}
