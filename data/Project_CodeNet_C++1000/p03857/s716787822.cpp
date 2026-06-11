#include <cstdio>
#include <vector>
#include <map>
using namespace std;

map<long long int, int> m;
vector<int> road[200005];
vector<int> adj[2][200005];
int clus[2][200005];
bool visited[2][200005];
int clusIdx;

void dfs(int type, int here){
	visited[type][here] = true;
	clus[type][here] = clusIdx;
	for(int i=0; i<adj[type][here].size(); ++i){
		int next = adj[type][here][i];
		if(!visited[type][next])
			dfs(type, next);
	}
}
int main(){
	int N, K, L, p, q;
	scanf("%d %d %d", &N, &K, &L);
	while(K--){
		scanf("%d %d", &p, &q);
		adj[0][p].push_back(q);
		adj[0][q].push_back(p);
	}
	while(L--){
		scanf("%d %d", &p, &q);
		adj[1][p].push_back(q);
		adj[1][q].push_back(p);
	}
	for(int j=0; j<2; ++j){
		clusIdx = 0;
		for(int i=1; i<=N; ++i){
			if(!visited[j][i]){
				++clusIdx;
				dfs(j, i);
			}
		}
	}
	for(int i=1; i<=N; ++i){
		long long int key = 1ll * clus[0][i] * 200005 + clus[1][i];
		if(m.find(key) == m.end())
			m[key] = 1;
		else
			++m[key];
	}
	for(int i=1; i<=N; ++i){
		long long int key = 1ll * clus[0][i] * 200005 + clus[1][i];
		printf("%d ", m[key]);
	}
}
