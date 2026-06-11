#include <bits/stdc++.h>

using namespace std;

bool isOK(int ma, int n) {
  for (int i = ma; i >= 1; --i) {
    if (n >= i) {
      n -= i;
    }
  }
  return n == 0;
}

int main() {
  int n;
  cin >> n;
  int left = 0, right = n;
  int ma = n;
  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    if (isOK(mid, n)) {
      right = mid;
      ma = mid;
    } else
      left = mid;
  }
  for (int i = ma; i >= 1; --i) {
    if (n >= i) {
      n -= i;
      cout << i << endl;
    }
  }
}