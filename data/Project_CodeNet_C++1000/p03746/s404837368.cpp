#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fst first
#define snd second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  VVI v(n);
  vector<bool> used(n, false);
  deque<int> dq;
  int fa, fc;
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    fa = a;
    fc = b;
    v[a].pb(b);
    v[b].pb(a);
  }
  dq.pb(fa);
  dq.pb(fc);
  used[fa] = true;
  used[fc] = true;

  while (true)
  {
    int u = dq.back();
    int count = v[u].size();
    for (auto p : v[u])
    {
      if (!used[p])
      {
        dq.pb(p);
        used[p] = true;
        break;
      }
      else
      {
        count--;
      }
    }
    if (count == 0)
    {
      break;
    }
  }
  while (true)
  {
    int u = dq.front();
    int count = v[u].size();
    for (auto p : v[u])
    {
      if (!used[p])
      {
        dq.pf(p);
        used[p] = true;
        break;
      }
      else
      {
        count--;
      }
    }
    if (count == 0)
    {
      break;
    }
  }

  out(dq.size());
  rep(i, dq.size())
  {
    cout << ++dq[i] << " ";
  }
  cout << endl;
  return 0;
}
