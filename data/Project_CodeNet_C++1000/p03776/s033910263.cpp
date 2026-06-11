#pragma region header
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define mp make_pair
#define mt make_tuple
#define rep1(i, n) for (decltype(+n) i = 0; i < (n); i++)
#define rrep1(i, n) for (auto i = n - 1; i > static_cast<decltype(i)>(-1); i--)
#define rep2(i, a, b) for (auto i = (a); i < (b); i++)
#define rrep2(i, a, b) for (auto i = b - 1; i >= a; i--)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1) (__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep2, rrep1) (__VA_ARGS__)
#define each(i, a) for (auto &&i : (a))
using namespace std;

using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vd = vector<ld>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using mii = map<int, int>;
using vm = vector<mii>;
using vvm = vector<vm>;

constexpr int INF = 1e18;
constexpr int MOD = 1e9 + 7;
int mod(int a) { return (a % MOD + MOD) % MOD; }
int m_add(int a, int b) { return (a + b) % MOD; }
int m_add(int a, int b, int c) { return (a + b + c) % MOD; }
int m_sub(int a, int b) { return (a + MOD - b) % MOD; }
int m_mul(int a, int b) { return a * b % MOD; }
int m_mul(int a, int b, int c) { return a * b % MOD * c % MOD; }
int m_bipow(int x, int y) {
  if (y == 0) return 1;
  else if (y == 1) return x % MOD;
  else if (y % 2 == 0) {
    int z = m_bipow(x, (int)(y / 2));
    return m_mul(z, z);
  } else {
    int z = m_bipow(x, (int)(y / 2));
    return m_mul(z, z, x);
  }
}
int m_inv(int x) { return m_bipow(x, MOD - 2); }
int m_div(int a, int b) { return m_mul(a, m_inv(b)); }

template <class T>
void SORT(T &a) { stable_sort(all(a)); }
template <class T>
void RSORT(T &a) { stable_sort(rall(a)); }
template <class T>
void rev(T &a) { reverse(rall(a)); }
template <class T>
void uniq(T &a) { a.erase(unique(all(a)), end(a)); }
template <class T>
auto min_of(T a) { return *min_element(all(a)); }
template <class T>
auto max_of(T a) { return *max_element(all(a)); }
template <class T>
int sum_of(T a) { return accumulate(all(a), 0ll); }
template <class T, class U>
auto sum_of(T a, U init) { return accumulate(all(a), init); }
template <class T, class U>
int count_of(T a, U i) { return count(all(a), i); }
template <class T, class U>
int lower_index(T a, U i) { return lower_bound(all(a), i) - begin(a); } // use member func for set
template <class T, class U>
int upper_index(T a, U i) { return upper_bound(all(a), i) - begin(a); }
template <class T, class U>
bool binary(T a, U i) { return binary_search(all(a), i); }
template <class T, class U>
bool has(T a, U i) { return find(all(a), i) != end(a); }
template <class T>
int sz(T a) { return a.size(); };

template <class T>
void COUT(T x) { cout << x << endl; }
template <class T, class U>
void COUT(T x, U y) { cout << x << ' ' << y << endl; }
template <class T, class U, class V>
void COUT(T x, U y, V z) { cout << x << ' ' << y << ' ' << z << endl; }
template <class T>
void CSP(T x) { cout << x << ' '; }
template <class T>
void CVEC(T v) {
  int c = v.size() - 1;
  for (size_t i = 0; i < c; i++) cout << v[i] << ' ';
  if (c > -1) cout << v[c];
  cout << endl;
}

template <class T>
bool amin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool amax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
vector<pair<T, int>> zip_vi(vector<T> v) {
  int n = sz(v);
  vector<pair<T, int>> w(n);
  for (int i = 0; i < n; i++) w[i] = make_pair(v[i], i);
  return w;
}
template <class T>
vector<pair<int, T>> zip_iv(vector<T> v) {
  int n = sz(v);
  vector<pair<int, T>> w(n);
  for (int i = 0; i < n; i++) w[i] = make_pair(i, v[i]);
  return w;
}
template <class T, class S>
vector<pair<T, S>> zip(vector<T> v, vector<S> w) {
  int n = min(sz(v), sz(w));
  vector<pair<T, S>> x(n);
  for (int i = 0; i < n; i++) x[i] = make_pair(v[i], w[i]);
  return x;
}
template <class T, class S>
pair<vector<T>, vector<S>> unzip(vector<pair<T, S>> v) {
  int n = sz(v);
  auto w = make_pair(vector<T>(n), vector<S>(n));
  for (int i = 0; i < n; i++) {
    w.first[i] = v[i].first;
    w.second[i] = v[i].second;
  }
  return w;
}
template <class T, class S>
vector<T> unzip_first(vector<pair<T, S>> v) {
  int n = sz(v);
  vector<T> w(n);
  for (int i = 0; i < n; i++) w[i] = v[i].first;
  return w;
}
template <class T, class S>
vector<S> unzip_second(vector<pair<T, S>> v) {
  int n = sz(v);
  vector<S> w(n);
  for (int i = 0; i < n; i++) w[i] = v[i].second;
  return w;
}

int ceil_div(int x, int y) { return (x - 1) / y + 1; }

#pragma endregion header

// no MOD
struct combination {
  vvi table;
  combination(int n): table(n + 1, vi(n + 1, 1)) {
    for (int i = 1; i <= n; i++) for (int j = 0; j <= i; j++)
      if(j % i > 0) table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
  }
  int operator()(int n, int k) { return table[n][k]; }
} comb(50);


void solve(int N, int A, int B, vi v) {
  RSORT(v);
  v.push_back(0);
  ld sum = 0;
  rep(i, A)sum += v[i];
  COUT(sum / A);
  int m = 1;
  while(v[0] == v[m])m++;
  if(m >= A) {
    int ans = 0;
    rep(i, A, min(B, m) + 1)ans += comb(m, i);
    COUT(ans);
  } else {
    int l = A - 1, r = A - 1;
    while(v[l] == v[r])l--;
    l++;
    while(v[l] == v[r])r++;
    COUT(comb(r - l, A - l));
  }
}


#pragma region main
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(22);

  int N;
  cin >> N;
  int A;
  cin >> A;
  int B;
  cin >> B;
  vi v(N);
  for(int i = 0 ; i < N ; i++){
    cin >> v[i];
  }
  solve(N, A, B, move(v));
}
#pragma endregion main
