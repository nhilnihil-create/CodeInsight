#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  int sum = 0;
  bool imp = true;
  rep(i, n) {
    cin >> v[i];
    if (v[i] % 10 != 0) imp = false;
    sum += v[i];
  }
  if (imp) cout << 0;
  else if (sum % 10 != 0) cout << sum;
  else {
    sort(v.begin(), v.end());
    rep(i, n) {
      if (v[i] % 10 != 0) {
        cout << sum - v[i];
        return 0;
      }
    }
  }
}
