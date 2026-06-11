#include <bits/stdc++.h>

using namespace std;

long long get (long long a, long long b) {
  if (b == 0) return -a;
  return 2LL * b * (a / b) + get(b, a % b);
}

int main() {
  long long n, x;
  cin >> n >> x;
  cout << n + get(min(x, n - x), max(x, n - x)) << endl;
  return 0;
}

