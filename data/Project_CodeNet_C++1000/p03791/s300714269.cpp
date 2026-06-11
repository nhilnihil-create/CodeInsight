// prosto beresh i bahaesh'

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = (int) 2e6 + 7;
const int MOD = (int) 1e9 + 7;

const double eps = 1e-7;

int n;
int x[N];

int t[N];

void build(int v = 1, int tl = 0, int tr = n - 1) {
  if (tl == tr) t[v] = x[tl] - 2 * tl;
  else {
    int mid = (tl + tr) / 2;
    build(v + v, tl, mid);
    build(v + v + 1, mid + 1, tr);
    t[v] = min(t[v + v], t[v + v + 1]);
  }
}

int gmin(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
  if (l > tr || r < tl) return MOD;
  if (l <= tl && tr <= r) return t[v];
  int mid = (tl + tr) / 2;
  return min(gmin(l, r, v + v, tl, mid), gmin(l, r, v + v + 1, mid + 1, tr));
}

bool good(int l, int r) {
  bool res = 1;
  if (l < r)
    res &= (gmin(l, r - 1) > - 2 * l);
  res &= (x[r] >= 2 * (r-l));
  return res;
}

int main() {
  #ifdef LOCAL
  freopen("in.txt", "r", stdin);
  #endif

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  sort(x, x + n);
  build();
  ll res = 1;
  for (int i = 1; i < n; i++) {
    int ans = i - 1;
    int l = 0, r = i - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (good(mid, i)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    int how = i - ans;
    res *= (how + 1);
    res %= MOD;
  }
  cout << res;
  return 0;
}