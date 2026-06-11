#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector <int> tr[N];
int p[N], SG[N];

void dfs(int x, int f){
	p[x] = f;
	for (int i = 0; i < (int)tr[x].size(); i++){
		if (tr[x][i] == f) continue;
		dfs(tr[x][i], x);
		SG[x] ^= SG[tr[x][i]] + 1;
	}
}

int main(){
	int n, u, v;
	scanf("%d",&n);
	for (int i = 1; i <= n - 1; i++){
		scanf("%d %d",&u,&v);
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	memset(SG, 0, sizeof(SG));
	dfs(1, 0);
	if (SG[1]) printf("Alice\n");
	else printf("Bob\n");
	return 0;
}