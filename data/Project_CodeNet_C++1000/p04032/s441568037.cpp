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
  string str;
  cin >> str;

  for (ll i = 0; i < (ll)str.size() - 1; i++) {
    if (str[i] == str[i + 1]) {
      printf("%lld %lld\n", i +1, i + 2);
      return 0;
    }
  }

  for (ll i = 0; i < (ll)str.size() - 2; i++) {
    if (str[i] == str[i + 2]) {
      printf("%lld %lld\n", i + 1, i + 3);
      return 0;
    }
  }

  puts("-1 -1");

  return 0;
}
