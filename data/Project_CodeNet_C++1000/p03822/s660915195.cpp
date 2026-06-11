#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> G[100000];
int memo[100000];

void dfs(int v){
	if(G[v].size() == 0){
		memo[v] == 0;
		return;
	}
	vector<int> va;
	for(int i = 0; i < G[v].size(); i++){
		dfs(G[v][i]);
		va.push_back(memo[G[v][i]]);
	}
	sort(va.begin(), va.end());
	reverse(va.begin(), va.end());
	for(int i = 0; i < va.size(); i++) memo[v] = max(memo[v], va[i] + i + 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int a;
		scanf("%d", &a);
		a--;
		G[a].push_back(i);
	}
	dfs(0);
	printf("%d\n", memo[0]);
	return 0;
}
