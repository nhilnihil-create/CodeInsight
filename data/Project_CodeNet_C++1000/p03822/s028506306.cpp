#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
#define coc g[node][i]
using namespace std;

typedef vector < int > vi;

int n, x;
vi g[N];

int dfs(int node){
	vi a;
	for(int i = 0; i < g[node].size(); i++){
		a.pb(dfs(coc));
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int ans = 0;
	// cout << node << " -> ";
	// for(int i = 0; i < a.size(); i++)cout << a[i] << " ";cout << endl;
	for(int i = 0; i < a.size(); i++)
		ans = max(ans, a[i] + i);
	return ans + 1;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d",&n);
	for(int i = 2; i <= n; i++){
		scanf("%d", &x);
		g[x].pb(i);
	}
	cout << dfs(1) - 1 << endl;;
	return 0;
}