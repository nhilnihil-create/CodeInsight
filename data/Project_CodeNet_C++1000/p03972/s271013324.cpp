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

int main()
{

  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(50) << setiosflags(ios::fixed);
  ll w, h;
  cin >> w >> h;
  ll p[100010], q[100010];
  smaller_queue<pll> que;
  rep(i, w)
  {
    cin >> p[i];
    que.push(MP(p[i], 0));
  }
  rep(i, h)
  {
    cin >> q[i];
    que.push(MP(q[i], 1));
  }

  ll ans = 0;
  ll used_cnt[2] = {};
  while (!que.empty())
  {
    ll cost = que.top().first;
    int type = que.top().second;
    que.pop();
    if (type == 0)
    {
      ans += cost * (h + 1 - used_cnt[1]);
      //cerr << cost << " " << (w + 1 - used_cnt[1]) << endl;
      used_cnt[0]++;
    }
    else
    {
      ans += cost * (w + 1 - used_cnt[0]);
      //cerr << cost << " " << (h + 1 - used_cnt[0]) << endl;
      used_cnt[1]++;
    }
  }
  cout << ans << endl;
  return 0;
}
