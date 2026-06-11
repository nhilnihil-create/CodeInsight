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

	int N; cin >> N;
	vector<ll> v(3 * N), h(3 * N+1);
	ll vsum = 0;
	rep(i, 3 * N){
		ll a; cin >> a;
		v[i] = a;
		h[i+1] = h[i] + v[i];
		vsum += a;
	}

	ll micost[MAX];
	ll macost[MAX];
	memr(micost, 0);
	memr(macost, 0);

	priority_queue<ll, vector<ll>, greater<ll> > q;
	rep(i, N){
		q.push(v[i]);
	}
	rep(i, N){
		int a = i + N;
		q.push(v[a]);
		micost[i+1] = micost[i] + q.top();
		q.pop();
	}
	priority_queue<ll> q2;
	reverse(ALL(v));
	rep(i, N){
		q2.push(v[i]);
	}
	rep(i, N){
		int a = i + N;
		q2.push(v[a]);
		macost[i+1] = macost[i] + q2.top();
		q2.pop();
	}
	reverse(ALL(v));
	// rep(i, N+1){
		// if(i) cout << " ";
		// cout << micost[i];
	// }
	// cout << endl;
	// rep(i, N+1){
		// if(i) cout << " ";
		// cout << macost[i];
	// }
	// cout << endl;
	ll sum = 0;
	rep(i, N){
		sum += v[i];
	}
	ll ans = -LLINF;
	// cout <<  endl;
	rep(i, N + 1){
		ll tmp = sum - micost[i];
		int b = N - i;
		ll tmp2 = vsum - sum  - macost[b];
		// cout << tmp << " " << tmp2 << endl;
		chmax(ans, tmp - tmp2);
		if(i == N) break;
		sum += v[i + N];
	}
	cout << ans << endl;
	return 0;
}
