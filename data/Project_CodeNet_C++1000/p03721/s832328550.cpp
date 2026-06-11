#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long int n, k;
  cin >> n >> k;
  map<long long int, long long int> mp;
  for (int i = 0; i < n; i++) {
    long long int a, b;
    cin >> a >> b;
    mp[a] += b;
  }
  long long int sum = 0;
  for (auto p : mp) {
    sum += p.second;
    if (sum >= k) {
      cout << p.first;
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}

