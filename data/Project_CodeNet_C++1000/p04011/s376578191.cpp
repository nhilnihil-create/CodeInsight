#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  
  int total = 0;
  for (int i = 1; i <= n; i++) {
    if (i <= k) {
      total += x;
    } else if (i > k) {
      total += y;
    }
  }
  cout << total << endl;
}