#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> ab(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ab.at(i) = make_pair(a, b);
  }
  vector<int> res(n, 0);
  rep(i, m) {
    int a = ab.at(i).first;
    int b = ab.at(i).second;
    res.at(a)++;
    res.at(b)++;
  }
  rep(i, n) {
    cout << res.at(i) << endl;
  }
  return 0;
}
