#define MOD_TYPE 2

#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
/*
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using multiInt = boost::multiprecision::cpp_int;
using lld = boost::multiprecision::cpp_dec_float_100;
*/

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
constexpr int INF = (int)1e9;
constexpr ll LINF = (ll)4e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-11;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define REPI(i, m, n) for (int i = m; i < (int)(n); ++i)
#define repi(i, n) REPI(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

inline void init_main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);
}
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
inline ll CEIL(ll a, ll b)
{
  return (a + b - 1) / b;
}
#pragma endregion

int main()
{
  init_main();

  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n - 1) a[i + 1] += a[i];
  vector<ll> b = a;
  // +-+-
  ll lazy = 0;
  ll sum = 0;
  rep(i, n)
  {
    a[i] += lazy;
    if (i % 2 == 0 && a[i] <= 0)
    {
      // +
      lazy += 1 - a[i];
      sum += 1 - a[i];
    }
    else if (i % 2 == 1 && a[i] >= 0)
    {
      // -
      lazy -= a[i] - (-1);
      sum += a[i] - (-1);
    }
  }

  ll Min = sum;

  // -+-+
  a = b;
  lazy = 0;
  sum = 0;
  rep(i, n)
  {
    a[i] += lazy;
    if (i % 2 == 1 && a[i] <= 0)
    {
      // +
      lazy += 1 - a[i];
      sum += 1 - a[i];
    }
    else if (i % 2 == 0 && a[i] >= 0)
    {
      // -
      lazy -= a[i] - (-1);
      sum += a[i] - (-1);
    }
  }

  chmin(Min, sum);
  cout << Min << "\n";
  return 0;
}
