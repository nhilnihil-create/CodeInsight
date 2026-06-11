#include <bits/stdc++.h>
using namespace std;

long long pow(int b, int p) {
  if (p == 0)
    return 1;
  if (p % 2 == 1)
    return b * pow(b, p - 1);
  else {
    long long t = pow(b, p / 2);
    return t * t;
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  cout << k * pow(k - 1, n - 1);
}
