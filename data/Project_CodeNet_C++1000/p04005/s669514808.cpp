#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  ll red = a[2] / 2 * a[0] * a[1];
  ll blue = (a[2] - (a[2] / 2)) * a[0] * a[1];
  cout << blue - red << endl;
}