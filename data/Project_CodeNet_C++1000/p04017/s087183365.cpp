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
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n;
  cin >> n;

  vll xs(n);
  rep(i, n) cin >> xs[i];

  ll l;
  cin >> l;

  ll h = 31;
  vvll nxtr(n, vll(h)), nxtl(n, vll(h)), nxtra(n, vll(h)), nxtla(n, vll(h));
  vll pow2(h);
  rep(i, n - 1) {
    nxtr[i][0] = Upper_bound(xs, xs[i] + l) - 1;
    nxtra[i][0] = i + 1;
    nxtl[i + 1][0] = Lower_bound(xs, xs[i + 1] - l);
    nxtla[i + 1][0] = i;
  }
  nxtr[n - 1][0] = -1;
  nxtra[n - 1][0] = -1;
  nxtl[0][0] = -1;
  nxtla[0][0] = -1;

  pow2[0] = 1;
  repLRE(j, 1, h - 1) {
    pow2[j] = pow2[j - 1] * 2;
    rep(i, n) {
      ll chk = nxtr[i][j - 1];
      if (chk == -1) {
        nxtr[i][j] = nxtra[i][j] = -1;
      } else {
        nxtr[i][j] = nxtr[nxtr[i][j - 1]][j - 1];
        nxtra[i][j] = nxtra[nxtr[i][j - 1]][j - 1];
      }
      chk = nxtl[i][j - 1];
      if (chk == -1) {
        nxtl[i][j] = nxtla[i][j] = -1;
      } else {
        nxtl[i][j] = nxtl[nxtl[i][j - 1]][j - 1];
        nxtla[i][j] = nxtla[nxtl[i][j - 1]][j - 1];
      }
    }
  }

  ll q;
  cin >> q;
  rep(i, q) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    ll ans = 0;
    if (a < b) {
      rrepLRE(j, h - 2, 0) {
        ll na = nxtr[a][j], naa = nxtra[a][j];
        ll pnaa = nxtra[a][j + 1];
        if ((pnaa == -1 || b < pnaa) && (naa != -1 && naa <= b)) {
          ans += pow2[j];
          if (b <= na) break;
          a = na;
        }
      }
    } else {
      rrepLRE(j, h - 1, 0) {
        ll na = nxtl[a][j], naa = nxtla[a][j];
        ll pnaa = nxtla[a][j + 1];
        if ((pnaa == -1 || b > pnaa) && (naa != -1 && naa >= b)) {
          ans += pow2[j];
          if (b >= na) break;
          a = na;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
