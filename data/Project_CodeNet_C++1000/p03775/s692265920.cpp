#include <bits/stdc++.h>
using namespace std;

int keta(long long n) {
  int cnt = 0;
  while (n > 0) {
    n /= 10;
    cnt++;
  }
  return cnt;
}

int f(long long a, long long b) { return max(keta(a), keta(b)); }

int main() {
  long long n, a, b;
  int fmax, kmin = INT_MAX;
  cin >> n;
  a = 1;
  while (a <= sqrt(n)) {
    if (n % a == 0) {
      b = n / a;
      fmax = f(a, b);
      kmin = min(kmin, fmax);
    }
    a++;
  }
  cout << kmin << endl;
}