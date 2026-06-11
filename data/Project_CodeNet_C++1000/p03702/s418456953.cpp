/**
 *    author:  tourist
 *    created: 20.11.2019 14:45:33       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int low = 0, high = (int) 1e9;
  while (low < high) {
    int mid = (low + high) >> 1;
    long long req = 0;
    for (int i = 0; i < n; i++) {
      req += (max(0LL, h[i] - (long long) mid * b) + (a - b - 1)) / (a - b);
    }
    if (req <= mid) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
  return 0;
}
