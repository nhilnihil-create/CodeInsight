#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, L; cin >> n >> L;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int knot = -1;
  for (int i = 0; i < n - 1; i++) {
  	if (a[i] + a[i + 1] >= L) {
      knot = i + 1;
      break;
    }
  }
  if (knot == -1) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for (int i = 1; i < knot; i++) cout << i << endl;
  for (int i = n - 1; i > knot; i--) cout << i << endl;
  cout << knot << endl;
}