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
  ll N;
  cin >> N;
  vl A(N, 0), B(N, 0);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  vl CA(N, 0), CB(N, 0);
  vl DA(N, 0), DB(N, 0);
  REP(i, N) {
    if (i == 0)
      CA[i] = A[i];
    else if (A[i - 1] != A[i]) {
      CA[i] = A[i];
    } else
      DA[i] = A[i];
  }
  RREP(i, N) {
    if (i == N - 1)
      CB[i] = B[i];
    else if (B[i + 1] != B[i]) {
      CB[i] = B[i];
    } else
      DB[i] = B[i];
  }
  bool ok = true;
  REP(i, N) {
    if (CA[i] != 0 && CB[i] != 0 && CA[i] != CB[i])
      ok = false;
    else if (CA[i] == 0 && DA[i] < CB[i])
      ok = false;
    else if (CB[i] == 0 && DB[i] < CA[i])
      ok = false;
  }
  if (!ok)
    cout << 0 << endl;
  else {
    ll ans = 1;
    REP(i, N) {
      if (CA[i] == 0 && CB[i] == 0)
        ans *= min(DA[i], DB[i]);
      ans %= MOD;
    }
    cout << ans << endl;
  }

  return 0;
}
