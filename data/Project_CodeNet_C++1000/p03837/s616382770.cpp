#pragma target("avx")
#pragma optimize("O3")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using PP = std::pair<ll,P>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define REP(i,b,e) for(ll i=b; i<e; i++)
#define ALL(vec) vec.begin(),vec.end()
#define PRINT(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define SCAN(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<PP> edges(m);
	REP(i, 0, m){
		scanf("%ld %ld %ld", &edges[i].se.fi, &edges[i].se.se, &edges[i].fi);
		edges[i].se.fi--;
		edges[i].se.se--;
	}
	
	std::vector<V> dist(n, V(n, 1e18));
	for(PP d: edges){
		dist[d.se.fi][d.se.se] = std::min(dist[d.se.fi][d.se.se], d.fi);
		dist[d.se.se][d.se.fi] = std::min(dist[d.se.se][d.se.fi], d.fi);
	}
	REP(k, 0, n) REP(i, 0, n) REP(j, 0, n) {
		dist[i][j] = std::min(dist[i][j], dist[i][k]+dist[k][j]);
	}

	int ans = 0;
	for(PP d: edges){
		if(dist[d.se.fi][d.se.se]<d.fi) ans++;
	}
	printf("%d\n", ans);
	return 0;

}

