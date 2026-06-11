#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
typedef long long ll;
int N, M, vis[MAX];
ll cz, cc, cn;
vector<int> adj[MAX];

bool dfs(int cur, int st){
	vis[cur] = st;
	bool ret = false;
	for(auto &next : adj[cur]){
		if(vis[next] != -1){
			if(vis[next] == vis[cur])	ret |= 1;
		}
		else{
			ret |= dfs(next, st ^ 1);
		}
	}
	return ret;
}

int main(){
	memset(vis, -1, sizeof(vis));
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= N; i++){
		if(vis[i] == -1){
			if(adj[i].empty()){
				cz++;
				continue;
			}
			bool flag = dfs(i, 0);
			if(flag) cc++;
			else cn++;
		}
	}
	cout << cz * cz + 2 * cz * N - 2 * cz * cz + (cc + cn) * (cc + cn) + cn * cn << endl;
	return 0;
}