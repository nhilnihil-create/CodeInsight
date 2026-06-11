#define MOD_TYPE 1

#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;
/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
*/
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
  vector<pll> p;
  ll before = -1;
  bool zero[100010] = {};
  rep(i, n)
  {
    if (a[i] > before)
    {
      p.emplace_back(MP(a[i], i));
      before = a[i];
    }
    else
    {
      zero[i] = true;
    }
  }

  ll d[100010];
  d[0] = a[0];
  REP(i, 1, p.size())
  {
    d[p[i].second] = p[i].first - p[i - 1].first;
  }

  ll Max_add[100010] = {};
  ll cnt[100010] = {};
  /*
  for (auto pi : p)
  {
    cerr << pi.first << " " << pi.second << endl;
  }*/

  rep(i, n)
  {
    auto itr = lower_bound(all(p), MP(a[i], -1LL));
    int j = itr->second;

    if (j == 0)
    {
      cnt[0] += a[i];
    }
    else
    {
      int j_prev = (itr - 1)->second;
      Max_add[j_prev]++;
      ll a_prev = (itr - 1)->first;
      cnt[j] += a[i] - a_prev;
    }
  }

  for (int i = 100005; i >= 0; i--)
    Max_add[i] += Max_add[i + 1];

  rep(i, n)
  {
    if (zero[i])
    {
      cout << 0 << "\n";
    }
    else
    {
      cout << Max_add[i] * d[i] + cnt[i] << "\n";
    }
  }

  return 0;
}
