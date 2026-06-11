#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int GCD(int a, int b) {
  if (a == 0) return b;
  return GCD(b % a, a);
}

void Output(bool ok) {
  cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  exit(0);
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (n == 1) Output(a[0] == k);
  vector<int> l = a;
  vector<int> r = a;
  for (int i = 0; i < n - 1; ++i) l[i + 1] = GCD(l[i], l[i + 1]);
  for (int i = n - 1; i > 0; --i) r[i - 1] = GCD(r[i - 1], r[i]);
  for (int i = 0; i < n; ++i) {
    int L = 0, R = 0;
    if (i > 0) L = l[i - 1];
    if (i < n - 1) R = r[i + 1];
    int g = GCD(L, R);
    if (a[i] < k) continue;
    if ((a[i] - k) % g == 0) Output(true);
  }
  Output(false);
  return 0;
}
