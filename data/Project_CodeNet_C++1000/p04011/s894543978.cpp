#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  int total = 0;
  if (n <= k) total += n * x;
  else total += (k * x) + ((n - k) * y);
  cout << total << endl;
}