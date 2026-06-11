#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <stdio.h>
using namespace std;
int N, M, Q; 
vector<int> E[100010]; 
int V[100010]; 
int D[100010]; 
int C[100010]; 
int ans[100010]; 
int memo[100010]; // これ未満の値が来たら打ち切ってよい
void bfs(int i){
	if(memo[V[i]] > D[i]) return; 
	queue<int> que;
	int dist[100010] = {}; 
	que.push(V[i]); 
	dist[V[i]] = D[i] + 1; 
	memo[V[i]] = D[i] + 1; 
	if(!ans[V[i]]) ans[V[i]] = C[i]; 
	while(que.size()){
		int p = que.front(); que.pop(); 
		if(dist[p] <= 1) break; 
		for(int j = 0; j < E[p].size(); j++){
			int q = E[p].at(j); 
			if(memo[q] < dist[p] - 1 && dist[q] == 0){
				que.push(q);
				dist[q] = dist[p] - 1;
				memo[q] = dist[q]; 
				if(!ans[q]) ans[q] = C[i];
			}
		}
	}
	return; 
}
int main(){
	cin >> N >> M; 
	fill(memo, memo+100010, -1); 
	for(int i = 0; i < M; i ++){
		int a, b; 
		scanf("%d%d", &a, &b); 
		a--; b--; 
		E[a].push_back(b); 
		E[b].push_back(a); 
	}
	cin >> Q; 
	for(int i = 0; i < Q; i++){
		scanf("%d%d%d", &V[i], &D[i], &C[i]);
		V[i] --; 
	}
	for(int i = Q-1; i >= 0; i--){
		bfs(i); 
	}
	for(int i = 0; i < N; i++){
		printf("%d\n", ans[i]);
	}
}