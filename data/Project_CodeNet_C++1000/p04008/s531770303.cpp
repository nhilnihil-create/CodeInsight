#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define MAX_N 100000
int N, K;
int p[MAX_N+1];
int ans = 0;
vector<int> gp[MAX_N+1];

int d[MAX_N+1];

void dfs(int x){
	d[x] = 1;
	for(int i=0; i<gp[x].size(); i++){
		dfs(gp[x][i]);
		if(d[gp[x][i]]==K && x!=1){
			ans++;
		}else if(x!=1){
			d[x] = max(d[x], d[gp[x][i]]+1);
		}
	}
}


int main(){
	scanf("%d%d", &N, &K);
	for(int i=1; i<=N; i++){
		scanf("%d", &p[i]);
	}	
	if(p[1] != 1){
		p[1] = 1; ans++;
	}
	for(int i=2; i<=N; i++){
		gp[p[i]].push_back(i);
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}