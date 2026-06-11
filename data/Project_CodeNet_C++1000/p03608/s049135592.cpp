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

ll N, M, R;
vector<ll> r;
vector<ll> g[300];
ll dist[300][300];

ll dp[1 << 8];

// s -> all, v -> now
ll bitdfs(ll s, ll v){
	if(dp[s] >= 0) return dp[s];

	if(s == (1 << R) -1){
		return dp[s] = 0;
	}

	ll res = LLINF;
	rep(i, r.size()){
		ll u = r[i];
		if(!(s >> i & 1)) {
			res = min(bitdfs(s | 1 << i, u) + dist[v][u], res);
		}
	}

	return dp[s] = res;
}

int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);

	cin >> N >> M >> R;
	r.resize(R);
	rep(i, R) {
		ll a; cin >> a;
		a--;
		r[i] = a;
	}

	rep(i, 300){
		fill(dist[i], dist[i]+300, LLINF);
	}
	rep(i, 300){
		dist[i][i] = 0;
	}


	rep(i, M){
		ll a, b, c; cin >> a >> b >> c;
		a--; b--;
		g[a].push_back(c);
		g[b].push_back(c);
		dist[a][b] = c;
		dist[b][a] = c;
	}

	rep(k, N){
		rep(i, N){
			rep(j, N){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}


	ll ans = LLINF;
	sort(ALL(r));
	do{
		ll res = 0;
		rep(i, r.size()-1){
			res += dist[r[i]][r[i+1]];
		}
		ans = min(res, ans);
	} while(next_permutation(ALL(r)));


	cout << ans << endl;

	return 0;
}
