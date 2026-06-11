#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i, n) cin >> x[i];

  int d = 0;
  rep(i, n) d += 2 * min(x[i], k - x[i]);
  cout << d << endl;
  return 0;
}