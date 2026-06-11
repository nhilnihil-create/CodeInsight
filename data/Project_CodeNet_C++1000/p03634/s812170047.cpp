#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define pb push_back
#define COUT(x) cout << (x) << endl
#define COUTF(x) cout << setprecision(15) << (x) << endl
#define ENDL cout << endl
#define DF(x) x.erase(x.begin())  // 先頭文字削除
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(ALL(x))
#define init() \
  cin.tie(0);  \
  ios::sync_with_stdio(false)
#define debug(x) cerr << "[debug] " << #x << ": " << x << endl;
#define debugV(v)                       \
  cerr << "[debugV] " << #v << ":";     \
  rep(i, v.size()) cerr << " " << v[i]; \
  cerr << endl;
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using P = pair<ll, ll>;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr double PI = 3.141592653589793238462643383279;
ll getDigit(ll x) {
  return x == 0 ? 1 : log10(x) + 1;
}

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

vector<P> factorize(ll n) {
  vector<P> result;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      result.pb({i, 0});
      while (n % i == 0) {
        n /= i;
        result.back().second++;
      }
    }
  }
  if (n != 1) {
    result.pb({n, 1});
  }
  return result;
}

vll divisor(ll n) {
  vll ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  SORT(ret);
  return (ret);
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  init();
  ll N;
  cin >> N;
  // vll a(N - 1);
  // vll b(N - 1);
  // vll c(N - 1);

  vector<vector<pair<ll, ll>>> to(N);
  rep(i, N - 1) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    to[a].pb({b, c});
    to[b].pb({a, c});
  }

  ll Q, K;
  cin >> Q >> K;
  K--;
  vector<P> q(Q);
  rep(i, Q) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    q[i] = {x, y};
  }

  vll dp(N, -1);
  queue<pair<ll, ll>> que;
  que.push({K, 0});

  while (!que.empty()) {
    pair<ll, ll> p = que.front();
    que.pop();

    if (dp[p.first] != -1) {
      continue;
    }
    dp[p.first] = p.second;

    rep(i, to[p.first].size()) {
      pair<ll, ll> a = to[p.first][i];
      que.push({a.first, p.second + a.second});
    }
  }

  rep(i, Q) {
    ll ans = dp[q[i].first] + dp[q[i].second];
    COUT(ans);
  }

  return 0;
}