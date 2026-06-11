#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
vector<int> e[maxn];
int vis[maxn], par[maxn], nxt[2][maxn];
int dfs(int rt, int pk){
	vis[rt] = 1;
	for(int i = 0; i < pk; i++){
		for(int go : e[rt]){
			if(!vis[go]){
				nxt[i][rt] = go;
				dfs(go, 1);
				break;	
			}
		}
	}
	return 0;
}
int main(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	memset(nxt, -1, sizeof(nxt));
	int tk = -1, nd = 1;
	for(int i = 1; i <= n; i++) if(e[i].size() == 1) tk = i;
	if(tk == -1) tk = 1, nd = 2;
	dfs(tk, nd);
	vector<int> a, b;
	if(nd == 1){
		int ck = tk;
		a.push_back(tk);
		while(nxt[0][ck] != -1) a.push_back(nxt[0][ck]), ck = nxt[0][ck];
	} else {
		int ck = tk;
		while(nxt[0][ck] != -1) a.push_back(nxt[0][ck]), ck = nxt[0][ck];
		reverse(a.begin(), a.end());
		a.push_back(tk);
		ck = tk;
		swap(nxt[1][ck], nxt[0][ck]);
		while(nxt[0][ck] != -1) a.push_back(nxt[0][ck]), ck = nxt[0][ck];
	}
	cout << a.size() << endl;
	for(int v : a) cout << v << " "; cout << endl;
	return 0;
}

