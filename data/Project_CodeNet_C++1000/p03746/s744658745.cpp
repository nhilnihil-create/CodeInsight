#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector <int> G[N];
int used[N];
deque <int> dq;

void dfs1(int x){
	used[x] = 1;
	for (int i = 0; i < G[x].size(); i++){
		if (!used[G[x][i]]){
			dq.push_back(G[x][i]);
			dfs1(G[x][i]);
			break;
		}
	}
}

void dfs2(int x){
	used[x] = 1;
	for (int i = 0; i < G[x].size(); i++){
		if (!used[G[x][i]]){
			dq.push_front(G[x][i]);
			dfs2(G[x][i]);
			break;
		}
	}
}

int main(){
	int n, m, u, v;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= m; i++){
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(used, 0, sizeof(used));
	dq.push_back(1);
	dfs1(1);
	dfs2(1);
	printf("%d\n", (int)dq.size());
	while (!dq.empty()){
		printf("%d", dq.front());
		dq.pop_front();
		if (!dq.empty()) printf(" ");
	}
	printf("\n");
	return 0;
}