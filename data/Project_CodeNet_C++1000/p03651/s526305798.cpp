#include <bits/stdc++.h>
using namespace std;

// calculate |gcd|.
// if  ether num is 0, return 0
long long GCD(long long left, long long right) {
  if (left == 0 || right == 0) return 0;
  if (left < 0) left *= -1;
  if (right < 0) right *= -1;
  if (left < right) swap(left, right);
  long long nextnum, ansgcd = -1;
  while (ansgcd == -1) {
    nextnum = left % right;
    if (nextnum == 0) ansgcd = right;
    left = right;
    right = nextnum;
  }
  return ansgcd;
}

long long LCM(long long left, long long right) {
  return left / GCD(left, right) * right;
}

long long n, k;
vector<long long> a;

bool solve();

int main() {
  cin >> n >> k;
  a.resize(n);
  for (auto& p : a) cin >> p;
  sort(a.begin(), a.end());
  if (solve())
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}

bool solve() {
  if (a[n - 1] < k) return 0;
  long long g = a[0];
  for (int i = 0; i < n; ++i) g = GCD(g, a[i]);
  return k % g == 0;
}