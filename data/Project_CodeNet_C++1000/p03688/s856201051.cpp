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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (a[n-1]>a[0]+1){
    cout<<"No\n";
    return 0;
  }
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == a[0]) {
      l++;
    } else {
      r++;
    }
  }
  for (int it = 0; it < 2; it++) {
    int min_unique = l + (r != 0);
    int max_unique = l + r / 2;
    if (min_unique <= (it ? a[n - 1] : a[0] + 1) && (it ? a[n - 1] : a[0] + 1) <= max_unique) {
      cout << "Yes\n";
      return 0;
    }
    if (r == 0) swap(l, r);
  }
  cout << "No\n";
}
