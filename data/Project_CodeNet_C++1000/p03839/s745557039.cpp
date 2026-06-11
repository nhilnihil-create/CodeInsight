
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

struct MaxFlowCalculator {
	int max_flow(int s, int t, const vector<vector<pair<int, int>>>& g) {
		struct edge_ { int to, cap, rev; };
		vector<bool> used(g.size(), false);
		vector<vector<edge_>> G(g.size());
		for (int i = 0; i < g.size(); i++) for (int j = 0; j < g[i].size(); j++)
		{
			int from = i, to = g[i][j].second;
			int cap = g[i][j].first;
			G[from].push_back({ to, cap, (int)G[to].size() });
			G[to].push_back({ from, 0, (int)G[from].size() - 1 });
		}
		auto dfs = [&](auto&& f, int v, int t, int fl)->int {
			if (v == t) return fl;
			used[v] = true;
			rep(i, G[v].size()) {
				edge_& e = G[v][i];
					if (!used[e.to] && e.cap > 0) {
					int d = f(f, e.to, t, min(fl, e.cap));
					if (d > 0) {
						e.cap -= d;
						G[e.to][e.rev].cap += d;
						return d;
					}
				}
			}
			return 0;
		};
		int flow = 0;
		while (1) {
			used.assign(used.size(), false);
			int f = dfs(dfs, s, t, INT_MAX);
			if (f == 0) return flow;
			flow += f;
		}
	}
};

class modint {
	static constexpr std::int_fast64_t Modulus = 1e9 + 7;
	using u64 = std::int_fast64_t;

public:
	u64 a;
	constexpr modint(const u64 x = 0) noexcept : a(x% Modulus) {}
	constexpr u64& value() noexcept { return a; }
	constexpr const u64& value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint operator*(const ll rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint& operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint& operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint& operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr operator u64() const { return a; }
};

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> vs(n);
	rep(i, n)cin >> vs[i];
	vector<ll> sums(n + 1, 0);
	vector<ll> plus(n + 1, 0);
	rep(i, n) {
		sums[i + 1] = sums[i] + vs[i];
		plus[i + 1] = plus[i] + (vs[i] >= 0 ? vs[i] : 0);
	}
	ll u = 0;
	for (int i = 0; i + k <= n;i++) {
		auto left = plus[i];
		auto right = plus[n] - plus[i + k];
		auto middle = sums[i + k] - sums[i];
		if (middle >= 0) {
			chmax(u, left + right + middle);
		}
		else {
			chmax(u, left + right);
		}
	}
	cout << u << endl;
    return 0;
}
