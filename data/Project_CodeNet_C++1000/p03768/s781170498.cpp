#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+10;
struct qyx{int num, d, ans;} p[N];
int vis[N], deep[N];
int len=0, cnt=0, sum, n, m, Q;

vector<int> e[N];

void Insert(int a, int b, int c) {
	p[++cnt].num = a;
	p[cnt].d = b;
	p[cnt].ans = c;
}

void dfs(int k, int d, int ans, int fa) {
	if(deep[k]>d) return;
	deep[k] = d;
	if(!vis[k]) vis[k] = ans, sum--;
	for(int i = 0; i<e[k].size(); i++) {
		int y = e[k][i];
		if(y == fa) continue;
		if(d) dfs(y, d-1, ans, k);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1, v, u; i <= m; i++) {
		scanf("%d%d", &u, &v);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	scanf("%d", &Q);
	for(int i = 1,u, v, w; i <= Q; i++) {
		scanf("%d%d%d", &u, &v, &w);
		Insert(u, v, w);
	}
	sum = n;
	for(int i = Q; i >= 1&&sum; i--) 
		dfs(p[i].num, p[i].d, p[i].ans, 0);	
	for(int i = 1; i <= n; i++)
		printf("%d\n", vis[i]);
	return 0;
}