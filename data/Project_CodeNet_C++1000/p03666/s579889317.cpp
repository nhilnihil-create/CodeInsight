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

void Output(bool ok) {
  cout << (ok ? "YES" : "NO") << endl;
  exit(0);
}

int main()
{
  ll n;
  cin >> n;
  ll a, b, C, D;
  cin >> a >> b >> C >> D;
  b = abs(a - b);
  a = 0;

  n--;
  for (ll x = 0; x <= n; ++x) {
    ll y = n - x;
    ll l, r;
    l = x * C - y * D;
    r = x * D - y * C;
    if (l <= b && b <= r) Output(true);
  }
  Output(false);

  return 0;
}
