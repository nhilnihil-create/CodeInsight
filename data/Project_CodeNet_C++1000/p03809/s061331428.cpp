#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector <int> tr[N];
int a[N], p[N], indeg[N];
long long rec[N];

void dfs(int x, int fa){
	long long sum;
	p[x] = fa;
	if ((int)tr[x].size() == 1) rec[x] = a[x];
	else{
		sum = 0;
		for (int i = 0; i < (int)tr[x].size(); i++){
			if (tr[x][i] == fa) continue;
			dfs(tr[x][i], x);
			sum += rec[tr[x][i]];
		} 
		rec[x] = a[x] * 2 - sum;
		if (rec[x] < 0){
			printf("NO\n");
			exit(0);
		}
	}
}

int main(){
	int n, u, v, root;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	memset(indeg, 0, sizeof(indeg));
	for (int i = 1; i <= n - 1; i++){
		scanf("%d %d",&u,&v);
		tr[u].push_back(v);
		tr[v].push_back(u);
		indeg[u]++; indeg[v]++;
	}
	if (n == 2){
		if (a[1] == a[2]) printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	for (int i = 1; i <= n; i++){
		if (indeg[i] > 1){
			root = i;
			break;
		}
	}
	dfs(root, 0);
	if (rec[root]){
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i <= n; i++){
		if (i == root) continue;
		if (rec[i] > min(a[i], a[p[i]])){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}