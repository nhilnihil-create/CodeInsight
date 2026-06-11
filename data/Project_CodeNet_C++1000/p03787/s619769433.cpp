#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

typedef long long ll;

const int N = 200000;

int n, m, col[N], Bi, uBi, Tak, cnt, Ot;
vector<int> G[N];	
bool mark[N];
bool f = 1;

void DFS(int v){
	mark[v] = 1;
	cnt++;
	for (auto u:G[v]){
		if (!mark[u]){
			col[u] = 1 - col[v];
			DFS(u);
		}else{
			if (col[u] == col[v]) f = 0;
		}
	}
}

int32_t main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int v, u;
		cin >> v >> u;
		G[v].pb(u), G[u].pb(v);
	}
	for (int i = 1; i <= n; i++){
		if (!mark[i]){
			cnt = 0;
			f = 1;
			DFS(i);
			if (cnt == 1) Tak ++;
			else{
				Ot += cnt;
				if (f) Bi++;
				else{
					uBi++;
				}
			}
		}
	}
	//cout << Bi << ' ' << uBi << ' ' << Tak << '\n';
	ll ans = 0;
	ans = 2 * Bi + uBi;
	ans += Tak * Tak + Ot * Tak * 2;
	ans += Bi * (Bi - 1) * 2;
	ans += 2 * Bi * uBi + uBi * (uBi - 1);
	cout << ans;
}
