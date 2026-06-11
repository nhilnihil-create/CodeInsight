#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, k;
  cin >> n >> k;

  bool digits[10] = {false};

  for (int i = 0; i < k; ++i) {
    int x; cin >> x;
    digits[x] = true;
  }

  int mx_int = ~(1 << 31);
  while (n < mx_int) {
    int tmp = n;

    while (tmp) {
      if (digits[tmp % 10]) break;
      else tmp /= 10;
    }

    if (!tmp) break;
    else n++;
  }

  cout << n << "\n";
}
