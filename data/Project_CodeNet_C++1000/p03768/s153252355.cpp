#include <bits/stdc++.h>
using namespace std;
const int maxn = 123456;
int seen[11][maxn], color[maxn];
vector<int> e[maxn];
int main(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	vector<tuple<int,int,int>> qs;
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int vi, di, ci; cin >> vi >> di >> ci;
		qs.push_back(make_tuple(vi, di, ci));
	}
	reverse(qs.begin(), qs.end());
	for(int i = 0; i < q; i++){
		int vi, di, ci; tie(vi, di, ci) = qs[i];
		if(!seen[di][vi]){
			queue<pair<int,int>> q;
			q.push({di, vi});
			seen[di][vi] = 1;
			while(!q.empty()){
				int d, v; tie(d, v) = q.front(); q.pop();
				if(color[v] == 0) color[v] = ci;
				if(d){
					for(int nxt : e[v]){
						if(!seen[d - 1][nxt]){
							q.push({d - 1, nxt});
							seen[d - 1][nxt] = 1;
						}
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << color[i] << endl;
	return 0;
}
