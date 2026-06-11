#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, a, b, c , d;
  cin >> n >> a >> b >> c >> d;
  n--;
  ll need_sum = b - a;
  for (int l = 0; l <= n; l++) {
    ll vl = -d * l + c * (n - l);
    ll vr = -c * l + d * (n - l);
    if (vl <= need_sum && need_sum <= vr) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
