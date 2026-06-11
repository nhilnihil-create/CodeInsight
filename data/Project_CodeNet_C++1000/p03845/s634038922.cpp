#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  for (int &x : t) {
    cin >> x;
  }
  int m;
  cin >> m;
  vector<int> p(m);
  vector<int> x(m);
  for (int i = 0; i < m; i++) {
    cin >> p.at(i) >> x.at(i);
  }
  int sum = 0;
  for (int x : t) {
    sum += x;
  }

  for (int i = 0; i < m; i++) {
    cout << sum - t.at(p.at(i) - 1) + x.at(i) << endl;
  }
}
