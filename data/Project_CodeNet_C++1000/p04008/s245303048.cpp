#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector <int> tr[N];
int a[N];
int ans, k;

int dfs(int x, int fa){
	int rec = -1;
	for (int i = 0; i < tr[x].size(); i++){
		if (tr[x][i] == fa) continue;
		rec = max(rec, dfs(tr[x][i], x));
	}
	rec++;
	if (x != 1 && rec == k - 1 && fa != 1){
		ans++;
		return -1;
	}
	return rec;
}

int main(){
	int n;
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	if (a[1] != 1) ans = 1;
	else ans = 0;
	for (int i = 2; i <= n; i++){
		tr[i].push_back(a[i]);
		tr[a[i]].push_back(i);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}