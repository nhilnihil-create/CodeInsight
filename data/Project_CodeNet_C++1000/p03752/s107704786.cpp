#define LOCAL
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rrep(i, n) for(int i=(n-1); i>=0; --i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define memr(dp, val) memset(dp, val, sizeof(dp))
using namespace std;
typedef long long ll;
static const int INTINF = (INT_MAX >> 1); // 10^9 + 10^7
static const ll LLINF = (LLONG_MAX >> 1);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);

  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];

  ll ans = LLINF;
  rep(bit, 1 << N){
  	vector<ll> b;
	rep(i, a.size()) b.push_back(a[i]);
    int popcnt = __builtin_popcount(bit);
    ll ma = 0;
    ll res = 0;
    rep(i, N){
      int tmp = N - i - 1;
      if(bit >> tmp & 1){
        if(b[i] <= ma){
          res += ma+1 - b[i];
          b[i] = ma+1;
        }
      }
      chmax(ma, b[i]);
    }

    int cnt = 0;
    ll ma2 = 0;
    rep(i, N){
      if(ma2 < b[i]){
        ma2=b[i];
        cnt++;
      }
    }
    if(cnt < K) continue;
    chmin(ans, res);
  }

  cout <<  ans << endl;
}
