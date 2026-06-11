#include <bits/stdc++.h>
using namespace std;
const int maxn = 2345;
int upto[maxn][maxn], sz[maxn], k;
vector<int> e[maxn], nvals[maxn][maxn];
int get_upto(int u, int v, int k){
	if(k < 0) return 0;
	return lower_bound(nvals[u][v].begin(), nvals[u][v].end(), k + 1) - nvals[u][v].begin();
}
int best(int u, int v, int dist){
	if(dist > k) return 0;
	int can = min(dist, k - dist);
	int tot = 0;
	vector<pair<int,int> > mvs;
	for(int nxt : e[u]) if(nxt != v){
		int up = get_upto(nxt, u, can - 1);
		mvs.push_back({nxt, up});
		tot += up;
	}
	int res = 0;
	for(auto mv : mvs){
		int ntot = tot - mv.second;
		res = max(res, ntot + best(mv.first, u, dist + 1));
	}
	return res + 1;
}
void push(int u, int v, int d, int x, int y){
	nvals[x][y].push_back(d);
	for(int nxt : e[u]) if(nxt != v) push(nxt, u, d + 1, x, y);
}
vector<pair<int,int> > eds;
int main(){
	int n; cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		int x, y; 
		cin >> x >> y;
	       	eds.push_back({x, y});	
		e[x].push_back(y); 
		e[y].push_back(x);
	}
	for(auto e : eds){
		push(e.first, e.second, 0, e.first, e.second);
		sort(nvals[e.first][e.second].begin(), nvals[e.first][e.second].end());
		swap(e.first, e.second);
		push(e.first, e.second, 0, e.first, e.second);
		sort(nvals[e.first][e.second].begin(), nvals[e.first][e.second].end());
	}
	int res = 0;
	for(int i = 1; i <= n; i++) {
		res = max(res, best(i, 0, 0));
	}
	cout << n - res << endl;
	return 0;
}
