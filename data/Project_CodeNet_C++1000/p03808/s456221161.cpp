#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);

  ll n;
  cin >> n;
  if (n == 1)
  {
    YES(true);
    return 0;
  }
  ll a[100010];
  rep(i, n) cin >> a[i];
  a[n] = a[0];
  ll sum = 0;
  rep(i, n) sum += a[i];
  ll sum2 = n * (n + 1) / 2;
  if (sum % sum2 != 0)
  {
    YES(false);
    return 0;
  }
  ll ope = sum / sum2;
  ll d[100010];
  rep(i, n)
  {
    d[i] = a[i + 1] - a[i];
    d[i] -= ope;
  }

  bool can = true;
  rep(i, n)
  {
    if (d[i] > 0 || d[i] % n != 0)
    {
      can = false;
      break;
    }
  }
  YES(can);
  return 0;
}
