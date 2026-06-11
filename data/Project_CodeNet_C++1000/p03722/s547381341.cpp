#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = 2147483647;
constexpr ll L_INF = 9223372036854775807LL;

//===

template <typename _Ty>
struct Edge
{
	int src, to;
	_Ty cost;

	constexpr Edge(int _to, _Ty _cost) noexcept : src(-1), to(_to), cost(_cost) {}
	constexpr Edge(int _src, int _to, _Ty _cost) noexcept : src(_src), to(_to), cost(_cost) {}
};

template <typename _Ty>
using WeightedGraph = std::vector<std::vector<Edge<_Ty>>>;

template <typename _Ty>
void bellman_ford(std::vector<_Ty>& dist, std::vector<bool>& closed, std::vector<int>& prev, const WeightedGraph<_Ty>& g, int s)
{
	constexpr _Ty inf = std::numeric_limits<_Ty>::max();
	int n = static_cast<int>(g.size());
	dist.resize(n, inf);
	closed.resize(n, false);
	prev.resize(n, -1);
	dist[s] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (const auto& edge : g[j]) {
				if (dist[j] != inf && dist[edge.to] > dist[j] + edge.cost) {
					dist[edge.to] = dist[j] + edge.cost;
					prev[edge.to] = j;
					if (i == n - 1) {
						closed[edge.to] = true;
					}
				}
			}
		}
	}
}



int main()
{
	int N, M;
	cin >> N >> M;

	WeightedGraph<ll> g(N);

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		g[a].emplace_back(b, -c);
	}

	Vl dist;
	Vi prev;
	vector<bool> closed;
	bellman_ford(dist, closed, prev, g, 0);

	if (closed[N - 1]) {
		cout << "inf" << endl;
	}
	else {
		cout << -dist[N - 1] << endl;
	}

	return 0;
}