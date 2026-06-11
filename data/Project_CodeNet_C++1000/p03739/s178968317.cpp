#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, sum1 = 0, sum2 = 0, b = 0, c = 0, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (i%2) {
      if (sum1+a < 0) {
        sum1 += a;
      } else {
        b += 1+(sum1+a);
        sum1 = -1;
      }
      if (sum2+a > 0) {
        sum2 += a;
      } else {
        c += 1-(sum2+a);
        sum2 = 1;
      }
    } else {
      if (sum1+a > 0) {
        sum1 += a;
      } else {
        b += 1-(sum1+a);
        sum1 = 1;
      }
      if (sum2+a < 0) {
        sum2 += a;
      } else {
        c += 1+(sum2+a);
        sum2 = -1;
      }
    }
  }
  cout << min(b,c);
}