#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

template<typename T>
vector<T> gen_v(size_t a) { return vector<T>(a); }
template<typename T, typename ...Ts>
auto gen_v(size_t a, Ts... ts) { return vector<decltype(gen_v<T>(ts...))>(a, gen_v<T>(ts...)); }
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) { for (auto &e : t) fill_v(e, v); }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	vector<vector<int>> G(N);
	vector<int> a(M), b(M); rep(i, 0, M) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	int Q; cin >> Q;
	vector<int> v(Q), d(Q), c(Q); rep(i, 0, Q) {
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}

	auto dp = gen_v<int>(N, 11);

	vector<int> ans(N);

	rrep(i, 0, Q) {
		using T = tuple<int, int>;
		queue<T> q;
		q.emplace(d[i], v[i]);
		while (q.size()) {
			int d, v; tie(d, v) = q.front(); q.pop();
			if (dp[v][d] != 0)continue;
			if (ans[v] == 0)ans[v] = c[i];
			rep(e, 0, d + 1)
				dp[v][e] = c[i];
			if (d == 0)continue;
			for (auto x : G[v])
				q.emplace(d - 1, x);
		}
	}

	rep(i, 0, N) {
		cout << ans[i] << endl;
	}




	return 0;
}