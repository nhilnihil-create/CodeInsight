#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k,total = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x * 2 < (k -x) * 2) {
      total += x * 2;
    } else {
      total += (k -x) * 2;
    }
  }
  cout << total << endl;
}
