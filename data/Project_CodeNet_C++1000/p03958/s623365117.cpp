#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k, t;
  cin >> k >> t;
  vector<int> a(t);
  rep(i, t) cin >> a[i];
  sort(a.rbegin(), a.rend());
  int sum = a[0];
  for (int i = 1; i < t; i++) sum -= a[i];
  cout << max(0, sum - 1) << endl;
  return 0;
}
