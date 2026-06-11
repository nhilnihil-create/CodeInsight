#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
static LL INF = (1LL<<62);

using LLPair = pair<LL, LL>;
using WeightedGraph = vector<vector<LLPair>>;
using PriorityQ = priority_queue<LLPair, vector<LLPair>, greater<LLPair>>;

void dijkstra(WeightedGraph &WG, vector<LL> &D, LL s){
	for(int i=0; i<D.size(); i++){
		D[i] = INF;
	}
	D[s] = 0;

	PriorityQ pq;
	pq.push(make_pair(0, s));
	while(!pq.empty()){
		LL pos = pq.top().second; pq.pop();
		for(auto nv : WG[pos]){
			LL to = nv.first;
			LL cost = nv.second;
			if(D[to] > D[pos] + cost){
				D[to] = D[pos] + cost; 
				pq.push(make_pair(D[to], to));
			}
		}
	}
	return;
}

void chminMapV(map<pair<LL, LL>, LL> &m, pair<LL, LL> &k, LL v){
	if(m.count(k) == 0){
		m[k] = v;
	}
	else{
		m[k] = min(m[k], v);
	}
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

	WeightedGraph WG(N);
	for(int i=0; i<M; i++){
		LL a, b, c; cin >> a >> b >> c;
		a--; b--;
		WG[a].push_back(make_pair(b, c));
		WG[b].push_back(make_pair(a, c));
	}

	map<pair<LL, LL>, LL> M;
	for(int i=0; i<r.size(); i++){
		for(int j=i+1; j<r.size(); j++){
			vector<LL> dist(N);
			dijkstra(WG, dist, r[i]);
			LL d = dist[r[j]];
			auto p1 = make_pair(r[i], r[j]);
			auto p2 = make_pair(r[j], r[i]);
			chminMapV(M, p1, d);
			chminMapV(M, p2, d);
		}
	}

	sort(r.begin(), r.end());
	LL ans = INF;
	do{
		LL w = 0;
		for(int i=0; i<r.size()-1; i++){
			auto p = make_pair(r[i], r[i+1]);
			w += M[p];
		}
		if(ans > w){
			ans = w;
		}
	}
	while(next_permutation(r.begin(), r.end()));

	printf("%lld\n", ans);
	return 0;
}
