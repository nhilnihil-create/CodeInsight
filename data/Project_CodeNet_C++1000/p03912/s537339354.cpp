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

  ll n, m;
  cin >> n >> m;
  vector<ll> x(n);
  rep(i, n) cin >> x[i];
  vector<ll> v[200010];
  rep(i, n)
  {
    v[x[i] % m].push_back(x[i]);
  }
  rep(i, m)
  {
    sort(all(v[i]));
  }
  ll same[200010] = {};
  rep(i, m)
  {
    rep(j, (int)v[i].size() - 1)
    {
      if (v[i][j] == v[i][j + 1])
      {
        same[i]++;
        j++;
      }
    }
  }
  ll ans = 0;
  for (int i = 0, j = m; i <= j; i++, j--)
  {
    if (i == 0 || i == j)
    {
      ans += (ll)v[i].size() / 2;
      continue;
    }
    if (v[i].size() >= v[j].size())
    {
      ll rem = v[i].size() - v[j].size();
      ans += v[j].size();
      ans += min(same[i], rem / 2);
    }
    else
    {
      ll rem = v[j].size() - v[i].size();
      ans += v[i].size();
      ans += min(same[j], rem / 2);
    }
  }
  cout << ans << endl;
  return 0;
}
