#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	int N, M;
	while(cin >> N >> M){
		vector<vector<int>> g(N);
		for(int i=0;i<M;i++){
			int a, b; cin >> a >> b;
			--a; --b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int Q; cin >> Q;
		vector<int> v(Q), d(Q), c(Q);
		for(int i=0;i<Q;i++){
			cin >> v[i] >> d[i] >> c[i];
			--v[i];
		}
		vector<int> color(N, 0);
		vector<int> time(N, -1);

		auto paint = [&](int pos, int t, int col){
			if(t < time[pos]) return;
			color[pos] = col;
			time[pos] = t;
		};

		for(int checkDist=0;checkDist<=10;checkDist++){
			vector<int> dist(N, 11);
			for(int i=Q-1;i>=0;i--){
				if(d[i] != checkDist) continue;
				if(dist[v[i]] == 0) continue;
				paint(v[i], i, c[i]);
				queue<int> qu; qu.push(v[i]);
				dist[v[i]] = 0;
				while(!qu.empty()){
					int p = qu.front(); qu.pop();
					if(dist[p] == checkDist) continue;
					for(auto next : g[p]){
						if(dist[next] <= dist[p] + 1) continue;
						dist[next] = dist[p] + 1;
						paint(next, i, c[i]);
						qu.push(next);
					}
				}
			}
		}
		for(auto res : color) cout << res << endl;
	}
}
