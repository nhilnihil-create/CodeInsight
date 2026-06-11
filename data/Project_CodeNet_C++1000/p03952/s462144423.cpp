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
  int n, x;
  cin >> n >> x;
  if (x == 1 || x == 2 * n - 1) {
    cout << "No\n";
    return 0;
  }
  if (n == 2) {
    cout << "Yes\n";
    cout << 1 << ' ' << 2 << ' ' << 3 << endl;
    return 0;
  }
  {
    deque <int> ans = {2 * n - 1, x, x - 1, x + 1};
    set <int> q;
    for (int x : ans) q.insert(x);
    for (int i = 1; i < 2 * n; i++) {
      if (!q.count(i)) { 
        if (i % 2 == 0) ans.push_back(i);
        else ans.push_front(i);
        q.insert(i);
      }
    }
    if (ans.size() == 2 * n - 1 && *q.begin() == 1 && *q.rbegin() == 2 * n - 1) {
      cout << "Yes\n";
      for (int t : ans) cout << t << '\n';
      return 0;
    }
  }
  {
    deque <int> ans = {1, x, x + 1, x - 1};
    set <int> q;
    for (int x : ans) q.insert(x);
    for (int i = 1; i < 2 * n; i++) {
      if (!q.count(i)) { 
        if (i % 2 == 0) ans.push_back(i);
        else ans.push_front(i);
        q.insert(i);
      }
    }
    if (ans.size() == 2 * n - 1 && *q.begin() == 1 && *q.rbegin() == 2 * n - 1) {
      cout << "Yes\n";
      for (int t : ans) cout << t << '\n';
      return 0;
    }
  }
}

