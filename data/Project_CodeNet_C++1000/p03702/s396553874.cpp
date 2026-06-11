#include <vector>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
vector<ll> hs;
int n;
ll a, b;

bool is_enough(ll x) {
  vector<ll> h = hs;
  ll cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (h[i] > x * b) {
      cnt += ceil((double)(h[i] - x * b) / (a - b));
    }
  }
  return cnt <= x;
}

int main() {
  scanf("%d %lld %lld", &n, &a, &b);

  ll ma = 0;
  for (int i = 0; i < n; ++i) {
    ll h;
    scanf("%lld", &h);
    hs.push_back(h);
    ma = max(h, ma);
  }

  ll l = -1, r = ma;
  while (l + 1 < r) {
    ll mid = (l + r) / 2;
    if (is_enough(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%lld\n", r);
  return 0;
}
