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
#define print(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define print(...)
#endif

ll dp[101][101][1000];

int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);

  ll N, W; cin >> N >> W;
  vector<ll> w(N), v(N);
  ll ori = -1;
  rep(i, N){
    cin >> w[i] >> v[i];
    if(ori == -1) ori = w[0];
    w[i] -= ori;
  }

  memr(dp, -1);
  ll ans = 0;
  dp[0][0][0] = 0;
  rep(i, N){
	  rep(j, 100){
		  rrep(k, 1000){
			  if(dp[i][j][k] == -1) continue;
			  chmax(dp[i+1][j][k], dp[i][j][k]);
			  chmax(ans, dp[i+1][j][k]);
			  if((j+1) * ori + k + w[i] > W) continue;
			  chmax(dp[i+1][j+1][k+w[i]], dp[i][j][k] + v[i]);
			  chmax(ans, dp[i+1][j+1][k+w[i]]);
		  }
	  }
  }

  cout << ans << endl;

	return 0;
}
