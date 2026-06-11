#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<long long, long long> c;
  for (auto ai : a) {
    c[ai]++;
    c[ai + 1]++;
    c[ai - 1]++;
  }
  long long ans = 0;
  for (auto ci : c) {
    ans = max(ans, ci.second);
  }
  cout << ans << '\n';
}