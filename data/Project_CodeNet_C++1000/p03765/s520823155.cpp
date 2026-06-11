#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_temp>
using smaller_queue = priority_queue<Q_temp, vector<Q_temp>, greater<Q_temp>>;

const ll MOD = (ll)(1e9 + 7);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const double PI = acos(-1.0);

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define possible(n) cout << ((n) ? "possible" : "impossible") << endl
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << endl;

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};
template <typename T>
class SegmentTree
{
private:
  using Fn = function<T(T, T)>;
  int N;
  vector<T> dat;
  const T unit; //単位元 a * e = a
  Fn func;

public:
  SegmentTree(int n_, Fn func_, T unit_) : func(func_), unit(unit_)
  {
    N = 1;
    while (N < n_)
      N *= 2;
    dat.assign(2 * N - 1, unit);
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
  string s, t;
  cin >> s >> t;
  auto add_mod = [](int a, int b) { return (a + b) % 3; };
  SegmentTree<int> sg_s(s.length(), add_mod, 0), sg_t(t.length(), add_mod, 0);
  rep(i, s.length())
  {
    sg_s.update(i, (s[i] == 'A' ? 1 : 2));
  }
  rep(i, t.length())
  {
    sg_t.update(i, (t[i] == 'A' ? 1 : 2));
  }
  int q;
  cin >> q;
  rep(qi, q)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, c--;
    YES(sg_s.query(a, b) == sg_t.query(c, d));
  }
  return 0;
}
