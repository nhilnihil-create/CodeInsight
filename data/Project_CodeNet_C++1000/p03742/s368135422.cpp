#include <cmath>
#include <cstdio>
#include <limits>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <string>
#include <array>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i, n) for (int i = n-1; i >= 0; --i)
#define REP(i, s, n) for (int i = s; i< (int)(n); ++i)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
ll inf = ll(1e18);
using ll1d = vector<ll>;
using ll2d = vector<ll1d>;
using ll3d = vector<ll2d>;

void solve(istream &ccin = cin, ostream &ccout = cout) {
  ll x, y;
  ccin >> x >> y;

  if(abs(x-y)>1)
    ccout << "Alice" << endl;
  else
    ccout << "Brown" << endl;



}

int main() {
  ios::sync_with_stdio(false);
  solve();
  return 0;
}