
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
int getval(const vl& v) {
  vl tmp = v;
  vl next_tmp;
  vl sorter(3);
  while (tmp.size() > 1) {
    next_tmp.clear();
    rep(i, tmp.size() - 2) {
      rep(k, 3) { sorter[k] = tmp[i + k]; }
      sort(ALL(sorter));
      next_tmp.emplace_back(sorter[1]);
    }
    tmp = next_tmp;
  }
  return tmp[1];
}
int main() {
  //
  ll n, x;
  cin >> n >> x;
  if (x == 1 || x == 2 * n - 1) {
    cout << "No" << endl;
    return 0;
  }
  vl ans(2 * n - 1, -1);
  ans[n - 1] = x;
  ans[n - 2] = 1;
  ans[n] = 2 * n - 1;
  int idx = 0;
  for (int val = 2; val < 2 * n - 1; val++) {
    if (val == x) continue;
    while (ans[idx] != -1) idx++;
    ans[idx] = val;
  }
  cout << "Yes" << endl;
  // cout << getval(ans) << endl;
  for (auto& x : ans) cout << x << endl;
  return 0;
}
