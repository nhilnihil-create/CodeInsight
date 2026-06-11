#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, sol = 0;
  cin >> n;
  vector<int> a(n), b;
  map<int, int> f;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  b = a;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    f[a[i]] = i % 2;
  }
  for (int i = 0; i < n; i++) {
    sol += (f[b[i]] != (i % 2));
  }
  cout << sol / 2 << "\n";
}
