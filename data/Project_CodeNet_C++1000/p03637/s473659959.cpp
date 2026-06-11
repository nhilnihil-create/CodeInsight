#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int main() {
  int n;
  cin >> n;
  int cnt4 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 4 == 0) cnt4 += 1;
    else if (x % 2 == 0) cnt2 += 1;
  }
  if (n/2 <= cnt4 || (cnt2/2 + cnt4 >= n/2)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
