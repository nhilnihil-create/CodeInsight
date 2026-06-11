#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map =
    tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

struct custom_hash {  // Credits: https://codeforces.com/blog/entry/62393
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
  size_t operator()(pair<int64_t, int64_t> Y) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
  }
};

template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, unordered_set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, multiset<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, ordered_set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R, class chash = std::hash<R>>
ostream& operator<<(ostream& os, unordered_map<L, R, chash> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R, class chash = std::hash<R>>
ostream& operator<<(ostream& os, gp_hash_table<L, R, chash> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int64_t random_long(long long l, long long r) {
  uniform_int_distribution<int64_t> generator(l, r);
  return generator(rng);
}
inline int64_t random_long() {
  uniform_int_distribution<int64_t> generator(LLONG_MIN, LLONG_MAX);
  return generator(rng);
}

/////-----------------------------\\\\\

#define ll long long
#define LL long long
#define ld long double
#define all(v) v.begin(), v.end()
#define uniq(v) v.erase(unique(all(v)), v.end())
#define pii pair<ll, ll>
#define ppi pair<ll, pii>
#define pb push_back
#define S second
#define F first
#define die() return 0;

#define md 1000000007
#define fmd 998244353
#define M 30001
#define N 20

#define RBTTYPE int
#define ordered_set                                    \
  tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag, \
       tree_order_statistics_node_update>

// typedef __int128_t ull;
typedef unsigned long long ULL;
const long long Inf = 1e18 + 20;
const long long INF64 = 3e18;

ll mod = 1000000007;

inline int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline int mul(int x, int y) { return (((long long)x) * y) % mod; }
inline int powr(int a, ll b) {
  int x = 1 % mod;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
T pw(T a, ll b) {
  T ans{1};
  while (b) {
    while (!(b & 1)) b >>= 1, a = (a * a);
    ans = (ans * a), --b;
  }
  return ans;
}
using ht = gp_hash_table<ll, ll, custom_hash>;
int solve() {
  int n, i, j, k, m, x, y, z;
  cin >> n;
  vector<int> a(n + 1);
  priority_queue<ppi, vector<ppi>> pq;
  map<int, int> cnt, mval;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
    if (mval.find(a[i]) == mval.end()) {
      mval[a[i]] = i;
    }
    mval[a[i]] = min(mval[a[i]], i);
  }
  for (auto x : cnt) {
    pq.push({x.F, {mval[x.F], x.S}});
  }
  vector<ll> ans(n + 1);
  while (pq.size() > 1) {
    ppi a = pq.top();
    if (a.S.F == 1) {
      break;
    }
    pq.pop();
    ppi b = pq.top();
    pq.pop();
    // trace(a, b);
    ans[a.S.F] += (a.F - b.F) * (a.S.S);

    pq.push({b.F, {min(b.S.F, a.S.F), b.S.S + a.S.S}});
  }
  while (pq.size()) {
    ppi a = pq.top();
    pq.pop();
    ans[1] += a.F * a.S.S;
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << "\n";
  }

  die();
}
void prec() {}
// #define FILE_INPUT

int main() {
#ifndef ONLINE_JUDGE
  double _tBeg = clock();
#endif
  // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with
  // unordered set unordered_map<long long, ll, custom_hash> safe_map;
  // gp_hash_table<long long, ll, custom_hash> safe_hash_table;

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

#ifdef FILE_INPUT
  char* inputFile = "input.txt";
  char* outputFile = "output.txt";
  freopen(inputFile, "r", stdin);
  freopen(outputFile, "w", stdout);
#endif

  int t;
  t = 1;
  prec();
  // cin >> t;

  int _case = 1;
  while (t--) {
    // cout<<"Case #"<<_case++<<": ";
    solve();
  }

#ifndef ONLINE_JUDGE
  double _tEnd = clock();
  // printf("\ntotal time %.6f\n", (_tEnd - _tBeg) / CLOCKS_PER_SEC);
#endif

  die();
}