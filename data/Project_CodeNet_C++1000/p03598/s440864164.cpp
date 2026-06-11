#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, i, m;
  cin >> n >> k;
  m=0;
  for(i=0;i<n;i++) {
    cin >> x;
    if(x <= k / 2) {
      m += 2 * x;
    }
    else {
      m += 2 * (k - x);
    }
  }
  cout << m << endl;
  return 0;
}
  