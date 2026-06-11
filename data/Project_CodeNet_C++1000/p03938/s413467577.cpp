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
  int n;
  cin >> n;
  vector <int> p(n);
  vector <int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    a[i] = i * n + 1;
    b[i] = (n - i) * n + 1;
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    b[p[i]] -= (n - 1 - i);
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << b[i] << ' ';
  }
}

