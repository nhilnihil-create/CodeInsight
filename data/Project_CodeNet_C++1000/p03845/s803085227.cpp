#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  int n, m, p, x;
  cin >> n;
  n++;
  vector<int> t(n);
  rep(i, 1, n) { cin >> t[i]; }

  int sum;
  cin >> m;
  rep(i, 0, m) {
    cin >> p >> x;
    sum = 0;
    rep(i, 1, n) {
      if (p == i) {
        sum += x;
      } else {
        sum += t[i];
      }
    }
    cout << sum << endl;
  }

  getchar();
}