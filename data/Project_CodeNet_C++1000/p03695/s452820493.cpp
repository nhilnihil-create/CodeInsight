#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> exist(8, 0);
  int r = 0;
  rep(i, n) {
    rep(j, 8) if (a[i] >= 400 * j && a[i] < 400 * (j+1)) exist[j] = 1;
    if (a[i] >= 3200) ++r;
  }

  int m = 0;
  rep(i, 8) m += exist[i];
  int M = m + r;
  if (m == 0) m = 1;
  printf("%d %d\n", m, M);
  return 0;
}