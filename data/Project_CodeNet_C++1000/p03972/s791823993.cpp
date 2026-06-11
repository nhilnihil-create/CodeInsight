#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

int main() {
  cout << fixed << setprecision(15);

  ll w, h;
  cin >> w >> h;

  priority_queue<ll, vll, greater<ll>> qx, qy;
  rep(i, w){
    ll p;
    cin >> p;
    qx.push(p);
  }
  rep(i, h){
    ll q;
    cin >> q;
    qy.push(q);
  }

  ll ans = 0;
  ll cx = 0, cy = 0;

  while(!qx.empty() || !qy.empty()){
    bool flag = true; // true -> x
    if(qx.empty()){
      flag = false;
    } else if (qy.empty()){
      // do nothing
    } else {
      if(qx.top() < qy.top()){
        // do nothing
      } else {
        flag = false;
      }
    }
    ll tv;
    if(flag){
      tv = qx.top();
      qx.pop();
      ans += tv*(h + 1 - cy);
      cx++;
    } else {
      tv = qy.top();
      qy.pop();
      ans += tv*(w + 1 - cx);
      cy++;
    }
  }

  cout << ans << endl;

  return 0;
}
