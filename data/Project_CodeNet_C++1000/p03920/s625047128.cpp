#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= 10000; i++) {
    sum += i;
    if (sum >= n) {
      int k = sum - n;
      for (int j = i; j >= 1; j--) {
        if (j == k) {
          continue;
        }
        cout << j << endl;
      }
      return 0;
    }
  }
  return 0;
}