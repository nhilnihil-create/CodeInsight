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

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;

const ll INF = 1LL << 32;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll curpos;
  cin >> curpos;
  ll ans = 0;
  for (ll i = 1; i < n; i++) {
    ll tmp;
    cin >> tmp;
    ll d = tmp - curpos;
    ll ad = a * d;
    if (ad <= b) {
      ans += a * d;
    } else {
      ans += b;
    }
    curpos = tmp;
  }

  cout << ans << endl;

  return 0;
}
