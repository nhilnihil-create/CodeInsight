#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int n, t;
  cin >> n >> t;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int mn = 1 << 30;
  vector<int> d;
  for (int i = 0; i < n; i++) {
    mn = min(mn, a[i]);
    d.push_back(a[i] - mn);
  }
  sort(d.begin(), d.end());

  cout << upper_bound(d.begin(), d.end(), d.back()) - lower_bound(d.begin(), d.end(), d.back()) << endl;

  return 0;
}