#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n;
  cin >> n;
  
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];

  int res = ~(1 << 31);
  for (int x = -100; x <= 100; ++x) {
    int cost = 0;
    for (int y: arr) cost += static_cast<int>(pow(abs(x - y), 2));
    res = min(res, cost);
  }

  cout << res << '\n';
}
