#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 2005

struct Info{
	void set(int arg_from,int arg_to,ll arg_cost){
		from = arg_from;
		to = arg_to;
		cost = arg_cost;
	}
	int from,to;
	ll cost;
};

Info info[SIZE];
ll min_dist[SIZE];
vector<int> G[SIZE];
bool check[SIZE];

void dfs(int node_id){

	for(int i = 0; i < G[node_id].size(); i++){

		int child = G[node_id][i];
		if(check[child])continue;

		check[child] = true;
		dfs(child);
	}
}


int main(){

	int V,E,start;
	scanf("%d %d",&V,&E);

	start = 0;

	for(int i = 0; i < V; i++)min_dist[i] = HUGE_NUM;
	min_dist[start] = 0;

	int from,to;
	ll cost;

	for(int i = 0; i < E; i++){
		scanf("%d %d %lld",&from,&to,&cost);
		from--;
		to--;
		info[i].set(from,to,-cost);
		G[to].push_back(from);
	}

	for(int i = 0; i < V; i++){

		check[i] = false;
	}
	check[V-1] = true;
	dfs(V-1);

	bool FLG = true,updated;
	Info tmp;

	for(int i = 0; i < V; i++){
		updated = false;
		for(int k = 0; k < E; k++){
			tmp = info[k];
			if(check[tmp.from] == true && min_dist[tmp.from] != HUGE_NUM && min_dist[tmp.to] > min_dist[tmp.from] + tmp.cost){
				min_dist[tmp.to] = min_dist[tmp.from] + tmp.cost;

				updated = true;
				if(i == V-1){
					FLG = false;
					break;
				}
			}
		}
		if(!updated)break;
		if(!FLG)break;
	}

	if(!FLG){
		printf("inf\n");
		return 0;
	}

	printf("%lld\n",-min_dist[V-1]);

	return 0;
}


