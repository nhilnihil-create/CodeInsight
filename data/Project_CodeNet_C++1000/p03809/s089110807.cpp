//2018-1-26
//miaomiao
//
#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
#define pb push_back
#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)
 
#define N (100000+5)
 
int rt, dig[N];
LL f[N], a[N];
vector<int> G[N];
 
#define v G[now][i]
 
LL Dfs(int now, int F){
	if(G[now].size() == 1) return a[now];

	LL sum = 0, mx = 0;
	For(i, 0, G[now].size() - 1){
		if(v == F) continue;

		LL res = Dfs(v, now);
		if(res < 0) return -1;

		sum += res; mx = max(mx, res);
	}

	if(sum - a[now] < 0) return -1;
	if(sum - a[now] <= min(sum >> 1, sum - mx)) return (a[now] << 1) - sum;
	return -1;
}
 
#undef v
 
int main(){
	int n, u, v;
 
	scanf("%d", &n);
	For(i, 1, n) scanf("%lld", &a[i]);
 
	For(i, 1, n-1){
		scanf("%d%d", &u, &v);
		G[u].pb(v); G[v].pb(u);
		++dig[u]; ++dig[v];
	}
	
	if(n == 2){
		if(a[1] == a[2]) puts("YES"); else puts("NO");
		return 0;
	}

	For(i, 1, n-1) if(dig[i] > 1) rt = i;
	printf("%s", Dfs(rt, 0) == 0? "YES": "NO");
 
	return 0;
}