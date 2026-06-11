#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n; cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; ++i) cin >> arr[i];
  sort(begin(arr), end(arr));

  if (n & 1) {
    for (int i = 0; i < n; ++i) {
      if ((i + 1) / 2 * 2 != arr[i]) {
        cout << 0 << "\n";
        return 0;
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      if (1 + i / 2 * 2 != arr[i]) {
        cout << 0 << "\n";
        return 0;
      }
    }
  }

  int res = 1;
  for (int i = 0; i < n /2; ++i) {
    res *= 2;
    res %= 1000000007;
  }

  cout << res << "\n";
}
