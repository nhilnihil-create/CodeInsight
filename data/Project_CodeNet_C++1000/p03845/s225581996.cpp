#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, m, all_time;

int main() {
  cin >> n;
  int entire = 0;
  vector<int> t(n);
  rep (i, n) {
    cin >> t[i];
  }
  all_time = 0;
  rep (i, n) {
    all_time += t[i];
  }
  cin >> m;
  vector<int> p(m);
  vector<int> x(m);
  rep (i, m) {
    cin >> p[i] >> x[i];
  }
  rep (i, m) {
    cout << all_time - t[p[i]-1] + x[i] << endl;
  }
  return 0;
}
