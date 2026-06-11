#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define fi first
#define sc second
#define pb push_back
#define COUT(x) cout << (x) << "\n"
#define COUTF(x) cout << setprecision(15) << (x) << "\n"
#define ENDL cout << "\n"
#define DF(x) x.erase(x.begin())  // 先頭文字削除
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll) x.size()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(ALL(x))
#define MAX(x, y, z) max(a, max(b, c))
#define MIN(x, y, z) min(a, min(b, c))
#define ANS cout << ans << "\n"
#define RETURN(x)    \
  cout << x << "\n"; \
  return 0
clock_t CLOCK;
#define START_TIMER CLOCK = clock()
#define SHOW_TIMER cerr << "time: " << (ld)(clock() - CLOCK) / 1000000 << "\n"
#define init() \
  cin.tie(0);  \
  ios::sync_with_stdio(false)
#define LINE cerr << "[debug] line: " << __LINE__ << "\n";
#define debug(x) cerr << "[debug] " << #x << ": " << x << "\n";
#define debugV(v)                       \
  cerr << "[debugV] " << #v << ":";     \
  rep(i, v.size()) cerr << " " << v[i]; \
  cerr << "\n";
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using mll = map<ll, ll>;
using qll = queue<ll>;
using P = pair<ll, ll>;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ld PI = 3.141592653589793238462643383279;
ll get_digit(ll x) {
  return to_string(x).size();
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

signed main() {
  init();
  ll N;
  cin >> N;
  vll count(9, 0);
  rep(i, N) {
    ll a;
    cin >> a;
    if (a <= 399) {
      count[0]++;
    } else if (a <= 799) {
      count[1]++;
    } else if (a <= 1199) {
      count[2]++;
    } else if (a <= 1599) {
      count[3]++;
    } else if (a <= 1999) {
      count[4]++;
    } else if (a <= 2399) {
      count[5]++;
    } else if (a <= 2799) {
      count[6]++;
    } else if (a <= 3199) {
      count[7]++;
    } else {
      count[8]++;
    }
  }

  ll ans_min = 0;
  ll ans_max = 0;
  rep(i, 8) {
    if (count[i] != 0) {
      ans_min++;
      ans_max++;
    }
  }
  ans_max = ans_min + count[8];
  if (ans_min == 0 && count[8] != 0) ans_min = 1;

  cout << ans_min << " " << ans_max << endl;
  return 0;
}