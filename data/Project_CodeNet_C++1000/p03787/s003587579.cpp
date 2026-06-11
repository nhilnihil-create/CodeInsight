#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector <int> G[N];
int used[N], rec[N];
int cnt1, cnt2, cnt3;
queue <int> q;

void bfs(int x){
	int cnt = 0, flag = 1;
	while (!q.empty()) q.pop();
	q.push(x);
	rec[x] = 1;
	while (!q.empty()){
		int u = q.front(); q.pop();
		cnt++;
		for (int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			if (!rec[v]){
				q.push(v);
				rec[v] = 3 - rec[u];
			}
			else if (rec[v] != 3 - rec[u]){
				flag = 0;
				break;
			}
		}
		if (!flag) break;
	}
	if (!flag) cnt3++;
	else if (cnt == 1) cnt1++;
	else cnt2++;
	while (!q.empty()) q.pop();
	q.push(x);
	used[x] = 1;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			if (!used[v]){
				q.push(v);
				used[v] = 1;
			}
		}
	}
}

int main(){
	int n, m, u, v;
	long long ans;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= m; i++){
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(used, 0, sizeof(used));
	memset(rec, 0, sizeof(rec));
	cnt1 = cnt2 = cnt3 = 0;
	for (int i = 1; i <= n; i++){
		if (!used[i]) bfs(i);
	}
	ans = 2LL * cnt1 * n - 1LL * cnt1 * cnt1 + 2LL * cnt3 * cnt2 + 1LL * cnt3 * cnt3 + 2LL * cnt2 * cnt2;
	printf("%lld\n", ans);
	return 0;
}