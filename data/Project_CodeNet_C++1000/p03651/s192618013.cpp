#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int g = a[0];
  for (int i = 1; i < n; ++i) g = gcd(g, a[i]);

  int m = *max_element(a.begin(), a.end());

  if (k % g == 0 && k <= m) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;

  return 0;
}