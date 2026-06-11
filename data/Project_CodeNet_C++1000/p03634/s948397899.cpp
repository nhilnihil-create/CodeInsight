#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

vector<vector<pair<ll, ll>>> G;
vector<ll> dist;

void bfs(ll v, ll pv, ll d)
{
	if (dist[v] != -1) return;
	dist[v] = d; 
	
	for (auto &nvP : G[v])
	{
		ll nv = nvP.first;
		ll nc = nvP.second;
		if (nv == pv) continue;
		bfs(nv, v, dist[v] + nc);
	}
}

int main(int argc, char **argv)
{
	ll N; cin >> N;
	G.resize(N);
	dist.assign(N, -1);;
	REP(i, N-1)
	{
		ll a, b, c; cin >> a >> b >> c;
		--a, --b;
		G[a].push_back(pair<ll, ll>(b, c));
		G[b].push_back(pair<ll, ll>(a, c));
	}

	ll Q, K; cin >> Q >> K;
	--K;
	bfs(K, -1, 0);

	REP(_, Q)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		std::cout << dist[a] + dist[b] << std::endl;
	}
}
