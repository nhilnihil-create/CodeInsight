#include <cmath>
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
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  vector <int> cost;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cost.push_back(max(a[i], 0));
  }
  auto f = [&] (vector <int> arr) {
    vector <ll> p;
    ll s=  0;
    for (int x : arr) {
      s += x;
      p.push_back(s);
    }
    return p;
  };
  auto l = f(cost), r = f(a);
  auto get = [&] (vector <ll> &a, int l, int r) {
    if (!l) return a[r];
    else return a[r] - a[l - 1];
  };
  ll ans = -1e18;
  for (int i = 0; i + k - 1 < n; i++) {
    ll me = max(0ll, get(r, i, i + k - 1));
    ans = max(ans, me + get(l, 0, n - 1) - get(l, i, i + k - 1));
  }
  cout << ans << endl;
}
