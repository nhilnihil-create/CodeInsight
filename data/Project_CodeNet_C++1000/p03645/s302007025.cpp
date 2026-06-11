#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N, M; cin >> N >> M;
	vector<vector<ll>> G(N);
	REP(i, M)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	queue<ll> que;
	que.push(0);
	vector<ll> dist(N, -1);
	dist[0] = 0;

	while (que.size())
	{
		ll now = que.front();
		que.pop();


		for (auto &nv : G[now])
		{
			if (dist[nv] != -1) continue;
			dist[nv] = dist[now] + 1;
			que.push(nv);
		}
	}

	bool ok = (dist[N-1] == 2);

	std::cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << std::endl;
	return 0;
}
