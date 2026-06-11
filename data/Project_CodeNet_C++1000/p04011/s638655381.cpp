#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, k, x, y;
  cin >> n >> k >> x >> y;

  int res = (x * min(k, n)) + y * max(0, (n - k));
  cout << res << "\n";
}
