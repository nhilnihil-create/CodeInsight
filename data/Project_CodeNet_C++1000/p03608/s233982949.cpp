#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
using Graph = vector<vector<LL>>;
static LL INF = (1LL<<62);
using LLPair = pair<LL, LL>;

// N:頂点の数、G：グラフ(隣接行列表現)
void WarshallFloyd(LL N, Graph &G, vector<vector<LL>> &D){
	D.assign(N, vector<LL>(N, INF));
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){ D[i][j] = G[i][j]; }
	}

	for(int k=0; k<N; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(D[i][k] != INF && D[k][j] != INF){
					D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
				}
			}
		}
	}
	return;
}

LL N, M, R;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<LL> r;
	cin >> N >> M >> R;

	for(int i=0; i<R; i++){
		LL t; cin >> t;
		r.push_back(t-1);
	}

	Graph G;
	G.assign(N, vector<LL>(N, INF));

	for(int i=0; i<M; i++){
		LL a, b, c; cin >> a >> b >> c;
		a--; b--;
		G[a][b] = min(G[a][b], c);
		G[b][a] = min(G[b][a], c);
	}
	
	vector<vector<LL>> D;
	WarshallFloyd(N, G, D);

	LL ans = INF;
	sort(r.begin(), r.end());
	do{
		LL w = 0;
		for(int i=0; i<r.size()-1; i++){
			LL d = D[r[i]][r[i+1]];
			w += d;
		}
		if(ans > w){
			ans = w;
		}
	}
	while(next_permutation(r.begin(), r.end()));

	printf("%lld\n", ans);
	return 0;
}

