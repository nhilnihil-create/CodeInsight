#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  rep(i, n) cin >> t[i];
  int m;
  cin >> m;
  vector<int> p(m), x(m);
  rep(i, m) cin >> p[i] >> x[i];
  rep(i, m) --p[i];

  rep(i, m) {
    int s = 0;
    rep(j, n) {
      if (j == p[i]) s += x[i];
      else s += t[j];
    }
    cout << s << endl;
  }
  return 0;
}