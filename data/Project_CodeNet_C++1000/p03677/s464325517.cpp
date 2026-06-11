#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

struct M {
  using T = lint;
  using U = lint;
  static void ap(T& a, const U& g) { a += g; }
  // static void ap(U& f, const U& g) { f += g; }
  static constexpr U id() { return 0; }
};

template<class M> struct ST {
  using T = typename M::T;
  using U = typename M::U;
  int n;
  V<T> t;
  V<U> u;

  ST(int n) : n(n) {
    t.resize(n, 0);
    u.assign(n, M::id());
  }

  void _ap(int i, const U& f) {
    if (i < n) M::ap(u[i], f);
    else M::ap(t[i - n], f);
  }

  T get(int i) {
    T res = t[i];
    for (i += n; i >>= 1;) M::ap(res, u[i]);
    return res;
  }

  void set(int l, int r, const U& f) {
    stack<int> s;
    for (int i = l + n; i >>= 1;) s.push(i);
    for (int i = r + n - 1; i >>= 1;) s.push(i);
    while (!s.empty()) {
      int i = s.top(); s.pop();
      _ap(2 * i, u[i]);
      _ap(2 * i + 1, u[i]);
      u[i] = M::id();
    }
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) _ap(l++, f);
      if (r & 1) _ap(--r, f);
    }
  }
};

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, m; cin >> n >> m;
  V<lint> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  ST<M> st(m + 1);
  for (int i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1]) {
      st.set(a[i], a[i + 1], -1);
    } else {
      st.set(0, a[i + 1], -1);
      st.set(a[i], m, -1);
    }
    st.set(a[i + 1] - 1, a[i + 1], (a[i + 1] - a[i] + m) % m);
  }
  V<lint> s(m);
  for (int i = 0; i < n - 1; i++) s[0] += min((a[i + 1] - a[i] + m) % m, a[i + 1]);
  for (int i = 0; i < m - 1; i++) s[i + 1] = s[i] + st.get(i);
  cout << *min_element(s.begin(), s.end()) << '\n';
}