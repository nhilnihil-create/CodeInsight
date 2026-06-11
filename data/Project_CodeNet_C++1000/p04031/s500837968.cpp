#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; ++i) cin >> arr[i];

  int res = ~(1 << 31);

  for (int x = -100; x <= 100; ++x) {
    int tmp = 0;
    for (int y: arr) {
      tmp += static_cast<int>(pow(x - y, 2));
    }
    res = min(res, tmp);
  }

  cout << res << "\n";
}
