#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int> > edges(n);
	int k;
	cin >> k;
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<vector<int> > dist(n, vector<int>(n, -1));
	for(int i = 0; i < n; i++){
		vector<pair<int,int> > bfs;
		int s = 0;
		bfs.push_back({i, 0});
		dist[i][i] = 0;
		while(s < (int)bfs.size()){
			int v = bfs[s].first;
			int d = bfs[s].second;
			s++;
			for(int w : edges[v]){
				if(dist[i][w] == -1){
					dist[i][w] = d+1;
					bfs.push_back({w, d+1});
				}
			}
		}
	}
	vector<pair<int,int> > cand;
	int dd = 0;
	if(k & 1){
		for(int i = 0; i < n; i++){
			for(int j : edges[i]){
				cand.push_back({i, j});
			}
		}
	} else {
		for(int i = 0; i < n; i++){
			cand.push_back({i, i});
		}
	}
	dd = k / 2;
	int best = 0;
	for(pair<int,int> a : cand){
		int keep = 0;
		for(int i = 0; i < n; i++){
			if(min(dist[a.first][i], dist[a.second][i]) <= dd){
				keep++;
			}
		}
		best = max(best, keep);
	}

	cout << n - best << '\n';
}