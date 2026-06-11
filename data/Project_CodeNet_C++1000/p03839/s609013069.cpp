#include <bits/stdc++.h>

using namespace std;

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define INF (1 << 30)
#define LLINF (1LL << 62)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

constexpr int MOD = 1000000007;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template <class T>
string to_string(T s);
template <class S, class T>
string to_string(pair<S, T> p);
string to_string(string s) { return s; }
string to_string(const char s[]) { return to_string(string(s)); }

template <class T>
string to_string(T v) {
  if (v.empty()) return "{}";
  string ret = "{";
  for (auto x : v) ret += to_string(x) + ",";
  ret.back() = '}';
  return ret;
}
template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

struct IO {
#ifdef _WIN32
  inline char getchar_unlocked() { return getchar(); }
  inline void putchar_unlocked(char c) { putchar(c); }
#endif
  string separator = " ";
  template <class T>
  inline void read(T& x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c != '-' && (c < '0' || '9' < c));
    bool minus = 0;
    if (c == '-') {
      minus = 1;
      c = getchar_unlocked();
    }
    x = 0;
    while ('0' <= c && c <= '9') {
      x *= 10;
      x += c - '0';
      c = getchar_unlocked();
    }
    if (minus) x = -x;
  }
  inline void read(string& x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c == ' ' || c == '\n');
    x.clear();
    do {
      x += c;
      c = getchar_unlocked();
    } while (c != ' ' && c != '\n' && c != EOF);
  }
  template <class T>
  inline void read(vector<T>& v) {
    for (auto& x : v) read(x);
  }
  template <class Head, class... Tail>
  inline void read(Head& head, Tail&... tail) {
    read(head);
    read(tail...);
  }
  template <class T>
  inline void write(T x) {
    char buf[32];
    int p = 0;
    if (x < 0) {
      x = -x;
      putchar_unlocked('-');
    }
    if (x == 0) putchar_unlocked('0');
    while (x > 0) {
      buf[p++] = (x % 10) + '0';
      x /= 10;
    }
    while (p) {
      putchar_unlocked(buf[--p]);
    }
  }
  inline void write(string x) {
    for (char c : x) putchar_unlocked(c);
  }
  inline void write(const char s[]) {
    for (int i = 0; s[i] != 0; ++i) putchar_unlocked(s[i]);
  }
  template <class T>
  inline void write(vector<T> v) {
    for (auto itr = v.begin(); itr + 1 != v.end(); ++itr) {
      write(*itr);
      write(separator);
    }
    write(v.back());
  }
  template <class Head, class... Tail>
  inline void write(Head head, Tail... tail) {
    write(head);
    write(separator);
    write(tail...);
  }
  template <class Head, class... Tail>
  inline void writeln(Head head, Tail... tail) {
    write(head, tail...);
    write("\n");
  }
  void set_separator(string s) { separator = s; }
} io;

template <typename T, typename E>
struct SegmentTree {
  typedef function<T(T, T)> F;
  typedef function<T(T, E)> G;
  typedef function<E(E, E)> H;
  typedef function<E(E, int)> P;
  int n;
  F f;
  G g;
  H h;
  P p;
  T d1;
  E d0;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(int n_, F f, G g, H h, T d1, E d0, vector<T> v = vector<T>(),
              P p = [](E a, int b) { return a; })
      : f(f), g(g), h(h), d1(d1), d0(d0), p(p) {
    init(n_);
    if (n_ == (int)v.size()) build(n_, v);
  }
  void init(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    dat.clear();
    dat.resize(2 * n - 1, d1);
    laz.clear();
    laz.resize(2 * n - 1, d0);
  }
  void build(int n_, vector<T> v) {
    for (int i = 0; i < n_; i++) dat[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--) dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
  }
  inline void eval(int len, int k) {
    if (laz[k] == d0) return;
    if (k * 2 + 1 < n * 2 - 1) {
      laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
      laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
    }
    dat[k] = g(dat[k], p(laz[k], len));
    laz[k] = d0;
  }
  T update(int a, int b, E x, int k, int l, int r) {
    eval(r - l, k);
    if (r <= a || b <= l) return dat[k];
    if (a <= l && r <= b) {
      laz[k] = h(laz[k], x);
      return g(dat[k], p(laz[k], r - l));
    }
    return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
                      update(a, b, x, k * 2 + 2, (l + r) / 2, r));
  }
  T update(int a, int b, E x) { return update(a, b, x, 0, 0, n); }
  T query(int a, int b, int k, int l, int r) {
    eval(r - l, k);
    if (r <= a || b <= l) return d1;
    if (a <= l && r <= b) return dat[k];
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return f(vl, vr);
  }
  T query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
  ll N, K;
  io.read(N, K);
  vector<ll> a(N);
  io.read(a);
  ll sum = accumulate(a.begin(), a.begin() + K, 0LL);
  ll pad = 0;
  FOR(i, K, N) if (a[i] > 0) pad += a[i];
  ll ans = max(sum, 0LL) + pad;
  FOR(i, K, N) {
    if (a[i - K] > 0) pad += a[i - K];
    if (a[i] > 0) pad -= a[i];
    sum += a[i] - a[i - K];
    ans = max(ans, max(sum, 0LL) + pad);
  }
  io.writeln(ans);
  return 0;
}