#include<bits/stdc++.h>
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<iostream>
#define f(i,n) for (int i=0;i<(n);i++)
#define f1(i,n) for (int i=1;i<=(n);i++)
#define pb push_back
#define ms(a) memset((a),0,sizeof(a))
#define ll long long
#define vi vector<int>
#define mp make_pair
#define die assert(fasle)
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define N (int)1e5+5
using namespace std;
int n, m, q;
vi g[N];
int v[N], d[N], c[N];
int ans[N];
int lft;
int mds[N];
void dfs(int vv, int dd, int cc) {
	if (!lft) return;
	if (dd < 0) return;
	if (!ans[vv])ans[vv] = cc;
	if (dd <= mds[vv]) return;
	mds[vv] = dd;
	//printf("%d %d %d\n", vv, dd, cc);
	for (int i = 0; i < g[vv].size(); i ++) {
		if (!g[vv][i])lft --;
		dfs(g[vv][i], dd-1, cc);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i ++) {
		scanf("%d%d%d", &v[i], &d[i], &c[i]);
	}
	for (int i = 1; i <= n; i ++) {
		mds[i] = -1;
	}
	lft = n;
	for (int i = q; i >= 1; i --) {
		//puts("");
		dfs(v[i], d[i], c[i]);
//		for (int j = 1; j <= n; j ++) {
//			printf("%d ", ans[j]);
//		}
//		puts("");
//		printf("%d\n", lft);
//		puts("");
		if (!lft) break;
	}
	for (int i = 1; i <= n; i ++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
