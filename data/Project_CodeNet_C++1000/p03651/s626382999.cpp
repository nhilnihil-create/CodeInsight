#include <bits/stdc++.h>
using namespace std;

// 再帰関数による最大公約数
int gcd(int x, int y) {
  return y ? gcd(y, x % y) : x;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  
  vector<int> a(n);
  int maximum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    maximum = max(maximum, a.at(i));
    if (a.at(i) == k) {
      cout << "POSSIBLE\n";
      return 0;
    }
  }
  
  if (maximum < k) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  
  int keep = 0;
  for (int i = 0; i < n; i++) keep = gcd(keep, a.at(i));
  
  if (k % keep == 0) cout << "POSSIBLE\n";
  else cout << "IMPOSSIBLE\n";
  return 0;
}