#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  for (auto & e : a) cin >> e;
  sort(a.begin(), a.end());

  ll s = a[0];
  int c = 1;
  for (int i = 1; i < n; ++i) {
    if (s * 2 < a[i]) {
      c = 1;
    } else {
      ++c;
    }
    s += a[i];
  }

  cout << c << endl;
  
}
