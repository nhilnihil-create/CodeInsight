#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;

int n;
std::vector<P> links[100010];

void dijkstra(int st, std::vector<ll> &dist){
	std::priority_queue<P, std::vector<P>, std::greater<P>> que;
	dist[st] = 0;
	que.emplace(0, st);
	while(!que.empty()){
		ll dis, from;
		std::tie(dis, from) = que.top();
		que.pop();
		if(dist[from]<dis) continue;
		for(P p: links[from]){
			ll to, cost;
			std::tie(to, cost) = p;
			if(dist[to]<dis+cost) continue;
			dist[to] = dis+cost;
			que.emplace(dist[to], to);
		}
	}
}
			
	

int main(){
	scanf("%d", &n);
	for(int i=0; i<n-1; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		links[a-1].emplace_back(b-1, c);
		links[b-1].emplace_back(a-1, c);
	}

	int q, k;
	scanf("%d %d", &q, &k);
	std::vector<ll> dist(n, 1e18);
	dijkstra(k-1, dist);
	
	for(int i=0; i<q; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%ld\n", dist[x-1]+dist[y-1]);
	}
	return 0;
}
