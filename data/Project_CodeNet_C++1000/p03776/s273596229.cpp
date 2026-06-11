#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
const long long INF = 1LL << 60;

// prime factorization (素因数分解)
// key: value of prime factor
// value: number of prime factor
map<ll, ll> prime_factorization(ll n) {
  std::map<ll, ll> prime_factors;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      prime_factors[i]++;
      n /= i;
    }
  }
  if (n != 1)
    prime_factors[n] = 1;
  return prime_factors;
}

vector<map<ll, ll>> m(51);

// 階乗の素因数分解
void init() {
  REP(i, 51) {
    m[i] = m[i - 1];
    auto primes = prime_factorization(i);
    FORm(it, primes) {
      m[i][it->first] += it->second;
    }
  }
}

ll combination(ll n, ll k) {
  auto mp = m[n];
  FORm(it, m[k]) {
    mp[it->first] -= it->second;
  }
  FORm(it, m[n - k]) {
    mp[it->first] -= it->second;
  }
  ll ans = 1;
  FORm(it, mp) {
    rep(i, it->second) {
      ans *= it->first;
    }
  }
  return ans;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(6);

  ll n, a, b;
  cin >> n >> a >> b;

  vll v(n);
  rep(i, n) {
    cin >> v[i];
  }
  sort(all(v), greater<ll>());

  ld max_ave = 0;
  ll ptn = 0;
  for (ll i = a; i <= b; i++) {
    ld value = accumulate(v.begin(), v.begin() + i, 0ll);
    chmax(max_ave, value / i);
  }

  init();

  for (ll i = a; i <= b; i++) {
    ld value = accumulate(v.begin(), v.begin() + i, 0ll);
    if (value / i >= max_ave) {
      ll end_val = v[i - 1];
      ll l = -1;
      ll r = -1;
      rep(i, n) {
        if (v[i] == end_val) {
          if (l == -1) {
            l = i;
          }
          r = i;
        }
      }
      ll comb_n = r - l + 1;
      ll comb_c = i - l;
      ptn += combination(comb_n, comb_c);
    }
  }

  cout << max_ave << endl;
  cout << ptn << endl;

  return 0;
}
