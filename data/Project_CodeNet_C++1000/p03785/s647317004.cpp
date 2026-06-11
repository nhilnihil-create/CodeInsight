#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  rep(i, n) cin >> t[i];

  sort(t.begin(), t.end());
  int ti = 0;
  vector<bool> taken(n, false);

  int num_bus = 0;
  while (ti < n) {
    int last = min(n-1, ti + c - 1);
    ++num_bus;
    if (t[last] <= t[ti] + k) {
      ti = last + 1;
    } else {
      int nti = ti;
      while (t[nti] <= t[ti] + k) ++nti;
      ti = nti;
    }
  }
  cout << num_bus << endl;
  return 0;
}