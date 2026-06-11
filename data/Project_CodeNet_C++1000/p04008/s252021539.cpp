#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int d[100001], deg[100001], used[100001], ans = 0;
typedef pair<int, int> P;

int main(){
	int N, K; cin >> N >> K;
	vector<int> G[N];
	int g[N];
	for(int i=0; i<N; i++){
		int a; cin >> a;
		a--;
		g[i] = a;
		if(i != 0){
			G[a].push_back(i);
			deg[a]++;
		}else{
			if(a != 0) ans++;
		}
	}
	priority_queue<P> pq;
	vector<int> d(N, INF);
	d[0] = 0;
	queue<int> que;
	que.push(0);
	while(que.size()){
		int now = que.front(); que.pop();
		for(int i=0; i<G[now].size(); i++){
			if(d[G[now][i]] == INF){
				d[G[now][i]] = d[now] + 1;
				que.push(G[now][i]);
			}
		}
	}
	for(int i=0; i<N; i++){
		if(deg[i] == 0 && d[i] > K){ pq.push(P(d[i], i));}
	}
	while(pq.size()){
		P p = pq.top(); pq.pop();
		if(p.first <= K){
			break;
		}
		if(used[p.second] == 1){
			continue;
		}
		int up = p.second;
		for(int i=0; i<K-1; i++){
			up = g[up];
		}
		ans++;
		queue<int> qu;
		qu.push(up);
        used[up] = 1;
		while(qu.size()){
			int aa = qu.front(); qu.pop();
			for(int i=0; i<G[aa].size(); i++){
				if(used[G[aa][i]] == 0){
					qu.push(G[aa][i]);
					used[G[aa][i]] = 1;
				}
			}
		}
		pq.push(P(d[g[up]], g[up]));
	}
	cout << ans << endl;
	return 0;
}
