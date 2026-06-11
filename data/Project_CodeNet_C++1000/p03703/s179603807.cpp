#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

const int MOD_TYPE = 1;
const ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-11;

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#pragma endregion

template <typename T>
class SegmentTree
{
private:
  using Fn = function<T(T, T)>;
  int N;
  vector<T> dat;
  T unit;
  Fn func;

public:
  SegmentTree() {}
  SegmentTree(int n_, Fn func_, T unit_) { init(n_, func_, unit_); }
  SegmentTree(vector<T> &v, Fn func_, T unit_) { init(v, func_, unit_); }

  void init(int n_, Fn func_, T unit_)
  {
    func = func_, unit = unit_;
    N = 1;
    while (N < n_)
      N *= 2;
    dat.assign(2 * N - 1, unit);
  }

  void init(vector<T> &v, Fn func_, T unit_)
  {
    func = func_, unit = unit_;
    N = 1;
    int sz = v.size();
    while (N < sz)
      N *= 2;
    dat.resize(2 * N - 1);
    for (int i = 0; i < N; ++i)
      dat[i + N - 1] = (i < sz ? v[i] : unit);
    for (int i = N - 2; i >= 0; --i)
      dat[i] = func(dat[i * 2 + 1], dat[i * 2 + 2]);
  }

  void update(int k, T a)
  {
    k += N - 1;
    dat[k] = a;
    while (k > 0)
    {
      k = (k - 1) / 2;
      dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]); //
    }
  }

  T query(int a, int b, int k = 0, int l = 0, int r = -1)
  {
    if (r < 0)
      r = N;
    if (r <= a || b <= l)
      return unit;
    if (a <= l && r <= b)
      return dat[k];
    else
    {
      T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return func(vl, vr);
    }
  }
};

int main()
{
  /*cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);*/
  ll n, k;
  scanf("%lld %lld", &n, &k);
  ll a[200010];
  rep(i, n) scanf("%lld", &a[i]);
  ll s[200010];
  s[0] = 0;
  rep(i, n) s[i + 1] = s[i] + a[i];
  map<ll, int> mp;
  rep(i, n)
  {
    mp[s[i] - k * i] = 1;
    mp[s[i] + a[i] - k * i - k] = 1;
  }
  int num = 0;
  for (auto &&p : mp)
  {
    p.second = num;
    num++;
  }
  ll ans = 0;
  SegmentTree<ll> sg(2 * n, plus<ll>(), 0);
  rep(i, n)
  {
    int j = mp[s[i] - k * i];
    sg.update(j, sg.query(j, j + 1) + 1);
    ans += sg.query(0, mp[s[i] + a[i] - k * i - k] + 1);
  }
  printf("%lld", ans);
  return 0;
}
