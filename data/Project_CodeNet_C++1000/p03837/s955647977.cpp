#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 105

struct Edge{

	int from,to,dist;
};

int N,M;
int min_dist[SIZE][SIZE];
Edge edge[1005];

int main(){

	scanf("%d %d",&N,&M);

	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++){
			if(k == i){

				min_dist[i][k] = 0;
			}else{

				min_dist[i][k] = BIG_NUM;
			}
		}
	}

	for(int i = 0; i < M; i++){

		scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].dist);
		edge[i].from--;
		edge[i].to--;

		min_dist[edge[i].from][edge[i].to] = min(min_dist[edge[i].from][edge[i].to],edge[i].dist);
		min_dist[edge[i].to][edge[i].from] = min(min_dist[edge[i].to][edge[i].from],edge[i].dist);
	}

	for(int mid = 0; mid < N; mid++){
		for(int start = 0; start < N; start++){
			if(min_dist[start][mid] == BIG_NUM)continue;
			for(int goal = 0; goal < N; goal++){
				if(min_dist[mid][goal] == BIG_NUM)continue;

				min_dist[start][goal] = min(min_dist[start][goal],min_dist[start][mid]+min_dist[mid][goal]);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < M; i++){
		bool FLG = false;

		for(int a = 0; a < N; a++){
			for(int b = 0; b < N; b++){
				if(b == a)continue;

				if(min_dist[a][b] == min_dist[a][edge[i].from]+edge[i].dist+min_dist[edge[i].to][b] ||
						min_dist[a][b] == min_dist[a][edge[i].to]+edge[i].dist+min_dist[edge[i].from][b]){
					FLG = true;
					break;
				}
			}
			if(FLG)break;
		}

		if(!FLG){

			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}
