#include <bits/stdc++.h>

using namespace std;

int numDigits(long long num) {
  if (num == 0) {
    return 1;
  }
  int r = 0;
  do {
    r++;
    num /= 10;
  } while (num != 0);
  return r;
}

int helper(long long n) {
  int r = numDigits(n);
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      r = min(r, numDigits(n / i));
    }
  }
  return r;
}

int main() {
  long long n;
  cin >> n;
  cout << helper(n) << endl;
}
