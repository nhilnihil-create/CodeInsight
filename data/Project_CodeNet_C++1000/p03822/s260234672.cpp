//Created Time:Tue 03 Dec 2019 03:49:01 PM CST
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define N 100005

using namespace std;

int n;
int f[N];

vector < int > G[N];

void dfs(int);
bool cmp(int ,int);

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		int x; scanf("%d", &x);
		G[x].push_back(i);
	}
	dfs(1); cout << f[1] << endl;
	return 0;
}

bool cmp(int x, int y){
	return f[x] < f[y];
}

void dfs(int u){
	int sz = G[u].size();
	for(int i = 0; i < sz; ++i)
		dfs(G[u][i]);
	sort(G[u].begin(), G[u].end(), cmp);
	for(int i = 0; i < sz; ++i)
		f[u] = max(f[u], f[G[u][i]]) + 1;
	return ;
}
