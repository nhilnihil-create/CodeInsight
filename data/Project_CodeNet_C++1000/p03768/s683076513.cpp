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
vector < int > ad[mx];
int col[12][mx], v[mx], d[mx], c[mx];
void dfs(int v, int d, int c){
	if(col[d][v])
		return;
	col[d][v] = c;
	if(!d)
		return;
	dfs(v , d - 1, c);
	for(auto u : ad[v])
		dfs(u , d - 1, c);
	return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	int n, m, q, a, b;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--, b--;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}
	for(int i = q - 1; i >= 0; i--)
		dfs(v[i] , d[i] , c[i]);
	for(int i = 0; i < n; i++)
		cout << col[0][i] << endl;
	return 0;
}

