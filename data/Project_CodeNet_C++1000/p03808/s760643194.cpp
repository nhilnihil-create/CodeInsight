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
  int n;
  cin >> n;
  vector <int> a(n);
  ll tot = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tot += a[i];
  }
  ll its = n * (ll) (n + 1) / 2;
  if (tot % its) {
    cout << "NO\n";
    return 0;
  }
  tot /= its;
  vector <ll> ders(n);
  for (int i = 0; i < n; i++) {
    ders[i] = a[(i + 1) % n] - a[i];
    ders[i] -= tot;
    if (ders[i] > 0 || ders[i] % n) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
