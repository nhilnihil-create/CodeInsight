#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vector<int> t(n), a(n);
  for (int i = 0; i < n; ++i) cin >> t[i] >> a[i];
  ll tk = 1, ao = 1;
  for (int i = 0; i < n; ++i) {
    ll res1 = (tk + a[i] - 1) / a[i];
    ll res2 = (ao + t[i] - 1) / t[i];
    tk = max(res1, res2) * a[i];
    ao = max(res1, res2) * t[i];
  }
  cout << tk + ao << endl;
  return 0;
}