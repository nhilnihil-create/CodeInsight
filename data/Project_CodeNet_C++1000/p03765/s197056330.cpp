#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 2147483647 / 2;
const long long int llINF = 9223372036854775807 / 2;

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end())
#define MIN(vec) *std::min_element(vec.begin(), vec.end())
#define ARGMAX(vec)                                                            \
  std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()))
#define ARGMIN(vec)                                                            \
  std::distance(vec.begin(), std::min_element(vec.begin(), vec.end()))
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
#define SP(a) setprecision(a)
#define SQRT(a) sqrt((long double)(a))
#define DPOW(a, b) pow((long double)(a), (long double)(b))
#define UNIQUE(vec)                                                            \
  do {                                                                         \
    sort(ALL((vec)));                                                          \
    (vec).erase(std::unique(ALL((vec))), (vec).end());                         \
  } while (0)

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp);
  } else {
    return (n * POW(n, m - 1));
  }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string S, T;
  ll q;
  cin >> S >> T >> q;
  ll N = S.size();
  ll M = T.size();
  vl DPS(N + 1, 0);
  vl DPT(M + 1, 0);
  REP(i, N) {
    if (S[i] == 'A')
      DPS[i + 1] = DPS[i] + 1;
    else
      DPS[i + 1] = DPS[i] - 1;
  }
  REP(i, M) {
    if (T[i] == 'A')
      DPT[i + 1] = DPT[i] + 1;
    else
      DPT[i + 1] = DPT[i] - 1;
  }
  vector<string> ans(q);
  REP(i, q) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll po = DPS[b] - DPS[a - 1];
    ll yo = DPT[d] - DPT[c - 1];
    ll poi = 0;
    ll yoi = 0;
    if (abs(po) % 3 == 0)
      poi = 0;
    else if ((po > 0 && po % 3 == 1) || (po < 0 && abs(po) % 3 == 2))
      poi = 1;
    else
      poi = 2;

    if (abs(yo) % 3 == 0)
      yoi = 0;
    else if ((yo > 0 && yo % 3 == 1) || (yo < 0 && abs(yo) % 3 == 2))
      yoi = 1;
    else
      yoi = 2;

    if (poi == yoi)
      ans[i] = "YES";
    else
      ans[i] = "NO";
  }
  REP(i, q) cout << ans[i] << endl;

  return 0;
}
