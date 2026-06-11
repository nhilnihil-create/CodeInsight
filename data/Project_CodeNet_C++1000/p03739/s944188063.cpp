#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n, ans1{}, ans2{}, s1{}, s2{}, t[2] = {1,-1};;
  cin >> n;
  vector<ll> a(n);
  for (ll &x: a) cin >> x;
  for (int i = 0; i != n; ++i) {
    s1 += a[i];
    s2 += a[i];
    auto p = t[i%2];
    if (s1 * p <= 0) {
      ans1 += abs(p - s1);
      s1 = p;
    }
    if (s2 * -p <= 0) {
      ans2 += abs(p + s2);
      s2 = -p;
    }
  }
  cout << min(ans1,ans2) << endl;
}
