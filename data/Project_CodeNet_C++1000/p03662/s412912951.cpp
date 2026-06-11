#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>

#define int long

const int INF = 1000000009;
const long LINF = 1123456789012345678;

typedef std::pair<int, int> P;

int n;
std::vector<int> edge[100005];
int dist[100005];
bool see[100005];

int fennec, snuke;

int dfs(int vis){
	int ret = 1;
	for(int i = 0; i < edge[vis].size(); i++){
		int next = edge[vis][i];
		if(!see[next]){
			see[next] = true;
			ret += dfs(next);
		}
	}
	return ret;
}

signed main(){
	scanf("%ld", &n);
	for(int i = 0; i < n-1; i++){
		int a, b;
		scanf("%ld %ld", &a, &b);
		edge[a-1].push_back(b-1);
		edge[b-1].push_back(a-1);
	}
	for(int i = 0; i < n; i++){
		dist[i] = -1;
	}
	dist[0] = 0;
	std::priority_queue<int> que;
	que.push(0);
	while(!que.empty()){
		int vis = que.top();
		que.pop();
		for(int i = 0; i < edge[vis].size(); i++){
			int next = edge[vis][i];
			if(dist[next] == -1){
				dist[next] = dist[vis] + 1;
				que.push(next);
			}
		}
	}
	
	/*
	for(int i = 0; i < n; i++){
		printf("%ld ", dist[i]);
	}
	printf("\n");
	//*/
	
	int vis = n-1;
	int next = 0;
	for(int i = 0; i < (dist[n-1]+1)/2; i++){
		for(int j = 0; j < edge[vis].size(); j++){
			next = edge[vis][j];
			if(dist[next] == dist[vis] - 1){
				if(i == (dist[n-1]+1)/2 - 1){
					break;
				}
				vis = next;
				break;
			}
		}
	}

	//printf("  %ld %ld\n", vis, next);
	
	/*
	for(int i = 0; i < edge[vis].size(); i++){
		if(edge[vis][i] == next){
			edge[vis].erase(edge[vis].begin() + i);
			break;
		}
	}
	for(int i = 0; i < edge[next].size(); i++){
		if(edge[next][i] == vis){
			edge[next].erase(edge[next].begin() + i);
			break;
		}
	}
	//*/
	see[vis] = true;
	see[next] = true;
	printf(dfs(next) > dfs(vis) ? "Fennec\n" : "Snuke\n");
	return 0;
}
