#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 100005;
const int mod = 998244353;

vector<int> gph[MAXN];
int d1[MAXN], d2[MAXN];

void dfs(int x, int p, int *d){
	for(auto &i : gph[x]){
		if(i != p){
			d[i] = d[x] + 1;
			dfs(i, x, d);
		}
	}
}

int main(){
	int n; scanf("%d",&n);
	for(int i=1; i<n; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0, d1);
	dfs(n, 0, d2);
	int r1 = 0, r2 = 0;
	for(int i=1; i<=n; i++){
		if(d1[i] <= d2[i]) r1++;
		else r2++;
	}
	if(r1 <= r2) puts("Snuke");
	else puts("Fennec");
}
