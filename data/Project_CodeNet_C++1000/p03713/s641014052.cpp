#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;

ll sub1(ll H, ll W) {
  ll ret;
  if (W % 3 == 0) {
    ret = 0;
  } else {
    ret = H;
  }
  return ret;
}

ll sub2(ll H, ll W) {
  ll ret = LONG_LONG_MAX;
  ll maxv, minv;
  for (ll i = 1; i <= H - 1; ++i) {
    ll a = i * W;
    ll b = (H - i) * (W/2);
    ll c = (H - i) * ((W+1)/2);
    maxv = max(a, max(b, c));
    minv = min(a, min(b, c));
    ret = min(ret, maxv - minv);
  }

  return ret;
}

int main() {
  ll H, W;

  cin >> H >> W;

  ll ans, ans1, ans2;
  ans1 = min(sub1(H, W), sub1(W, H));
  ans2 = min(sub2(H, W), sub2(W, H));
  ans = min(ans1, ans2);

  cout << ans << endl;

  return 0;
}
