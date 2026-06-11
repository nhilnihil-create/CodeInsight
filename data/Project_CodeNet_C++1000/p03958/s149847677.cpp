#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int k, t;
  cin >> k >> t;
  
  vector<int> a(t);
  int keep = -1;
  for (int i = 0; i < t; i++) {
    cin >> a.at(i);
    if (a.at(i) > k / 2) keep = a.at(i);
  }
  
  if (keep == -1) {
    cout << "0\n";
    return 0;
  }
  
  int ans = 0;
  keep -= (k + 1) / 2;
  if (k % 2 == 1) ans = keep * 2;
  else {
    ans = 1;
    keep--;
    ans += keep * 2;
  }
  
  cout << ans << '\n';
}