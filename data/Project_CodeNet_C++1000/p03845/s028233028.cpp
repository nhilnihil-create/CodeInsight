#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n; cin >> n;

  int arr[n];
  memset(arr, 0, sizeof(arr));

  int s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    s += arr[i];
  }

  int m; cin >> m;
  for (int i = 0; i < m; ++i) {
    int p, x;
    cin >> p >> x;
    int res = s - arr[p - 1] + x;
    cout << res << "\n";
  }
}
