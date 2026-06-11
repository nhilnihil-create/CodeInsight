#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(int i=int(m-1); i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) a.begin(), a.end()
#define fst first
#define snd second
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> inline int Log2(T& x) {int k; for(k=0; (T(1)<<k)<=x; ++k); return k;} // number of binary digits


template<typename T>
vector<int> compress(vector<T> &v) {
  vector<T> t = v;
  sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
	vector<int> r(v.size());
  for (int i = 0; i < v.size(); i++) {
    r[i] = lower_bound(t.begin(), t.end(), v[i]) - t.begin();
  }
	return r;
}

template<typename T>
struct BIT {
  int n; vector<T> d;
  BIT(int n=0) : n(n), d(n+1) {}
  void add(int i, T a=1) {
    for (i++; i <= n; i += i & -i) d[i] += a;
  }
  // sum [0, i)
  T sum(int i) {
    if (i == 0) return 0;
    T x = 0;
    for (; i > 0; i -= i & -i) x += d[i];
    return x;
  }
};


int main() {
  ll N, K; cin >> N >> K;
  Vll a(N);
  rep(i, N) cin >> a[i];

  Vll S(N+1);
  rep(i, N) S[i+1] = S[i] + a[i] - K;
  V Sc = compress(S);

  int M = *max_element(all(Sc)) + 1;
  BIT<int> bit(M);

  ll ans = 0;
  rep(i, N+1) {
    int x = Sc[i];
    ans += bit.sum(x+1);
    bit.add(x);
  }
  cout << ans << endl;
  return 0;
}
