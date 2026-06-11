#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <random>
#include <iomanip>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillDouble(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%lf", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

const int mod = 1000000007;
const int MAX_V = 100005;

int anim[MAX_V];
int n;
string s;

bool dfs(int x) {
  int prev, next;
  if (x == 0) {
    prev = n-1;
    next = 1;
  } else if (x == n-1) {
    prev = n-2;
    next = 0;
  } else {
    prev = x-1;
    next = x+1;
  }

  bool same;
  if (anim[x] == 1 && s[x] == 'o') {
    same = true;
  } else if (anim[x] == -1 && s[x] == 'x') {
    same = true;
  } else {
    same = false;
  }

  if (same) {
    if (anim[prev] && anim[next] && (anim[prev] != anim[next])) {
      return false;
    } else if (anim[prev] && anim[next]) {
      return true;
    } else if (anim[prev]) {
      anim[next] = anim[prev];
      return dfs(next);
    } else {
      anim[prev] = anim[next];
      return dfs(prev);
    }
  } else {
    if (anim[prev] && anim[next] && (anim[prev] == anim[next])) {
      return false;
    } else if (anim[prev] && anim[next]) {
      return true;
    } else if (anim[prev]) {
      anim[next] = -anim[prev];
      return dfs(next);
    } else {
      anim[prev] = -anim[next];
      return dfs(prev);
    }
  }
}

void init() {
  rep(i, n) {
    anim[i] = 0;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  cin >> s;

  bool res = false;

  for(int i : {1, -1}) {
    for(int j : {1, -1}) {
      init();
      anim[0] = i;
      anim[1] = j;
      res = dfs(1) && dfs(0);
      if(res) break;
    }
    if(res) break;
  }

  if (res) {
    rep(i, n) {
      if (anim[i] == 1) {
        cout << "S";
      } else {
        cout << "W";
      }
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
