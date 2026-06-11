///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
const int mx = 1000 * 100 + 5;
int c[mx], n, cnt = 0, is, bi, nbi;
vector < int > ad[mx];
bool mark[mx], b;
void dfs(int v){
	mark[v] = 1;
	for(auto u : ad[v]){
		if(c[u] == c[v])
			b = 0;
		if(!mark[u]){
			c[u] = 1 - c[v];
			dfs(u);
		}
	}
	return;
}
void dfs_all(){
	memset(c , -1 , sizeof c);
	for(int i = 0; i < n; i++){
		if(!mark[i]){
			cnt++;
			b = 1;
			c[i] = 1;
			if(sz(ad[i])){
				dfs(i);
				if(b)
					bi++;
				else
					nbi++;
			}
			else
				is++;
		}
	}
	return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	int m, u, v;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u--, v--;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	dfs_all();
//	cout << is << " " << bi << " " << nbi << endl;
	cout << (bi + nbi) * (bi + nbi) + bi * bi + 2 * n * is - is * is << endl;
	return 0;
}
