#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T & ref, const T  value) {
	if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T & ref, const T value) {
	if (ref < value) ref = value;
}

struct topoloricalSort_runnner {
	typedef vector<vector<int>> Graph;
	vector<int> input;

	bool topologicalSort(const Graph& graph, vector<int>& order) {
		int n = graph.size();
		//入次数
		input.assign(n, 0);
		rep(i, n) {
			for (auto dest : graph[i]) {
				input[dest]++;
			}
		}
		//rootを幅優先探索
		queue<int> q;
		rep(i, n) {
			if (input[i] == 0) {
				q.push(i);
			}
		}
		int multiple = 0;
		while (!q.empty()) {
			//順位が一位に決まらない
			if (q.size() >= 2) {
				multiple = 1;
			}
			auto id = q.front(); q.pop();
			order.push_back(id);
			for (auto next : graph[id]) {
				//すべての親を処理し終わったら処理する
				input[next]--;
				if (input[next] == 0) {
					q.push(next);
				}
			}
		}
		return multiple;
	}
};


int main() {
	ll n,k;
	cin >> n >> k;
	vector<ll> as(n);
	vector<vector<ll>> rev(n);
	rep(i, n) {
		cin >> as[i];
		as[i]--;
	}
	ll sum = 0;
	if (as[0] != 0) {
		sum++;
		as[0] = 0;
	}
	rep(i, n) {
		rev[as[i]].push_back(i);
	}
	vector<ll> dist(n, -1);
	function<ll(ll, ll)> dfs = [&](ll current, ll parent){
		if (dist[current] >= 0) return dist[current];
		ll u = 0;
		for (auto p : rev[current]) {
			if (p == current) continue;
			ll d = dfs(p, current);
			chmax(u, d);
		}
		if (u >= k - 1 && parent != 0) {
			sum++;
			dist[current] = 0;
			return dist[current];
		}
		u++;
		//cout << current << " " << u << endl;
		dist[current] = u;
		return u;
	};
	dfs(0, 0);
	cout << sum << endl;
	return 0;
}
