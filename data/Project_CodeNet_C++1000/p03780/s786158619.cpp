#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = min(a[i], k);
  }
  
  sort(a.begin(), a.end());
  int l = 0,r = n;
  while (l < r) {
  
    int mid = (l + r) / 2;
    bitset<5005> b;
    b[0] = 1;
    for (int j = 0; j < n; ++j) {
      if (j == mid) continue;
      b |= (b << a[j]);
    }

    bool req = 0;
    for (int j = 0; j < k; ++j) {
      if (b[j] && j + a[mid] >= k) req = 1;
    }

    if (req) r = mid;
    else l = mid + 1;
  }

  cout << l << '\n';

}
