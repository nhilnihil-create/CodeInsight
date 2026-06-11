#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 200005

int N,M;
bool check[SIZE];

int main(){

	scanf("%d %d",&N,&M);
	for(int i = 0; i < N; i++){

		check[i] = false;
	}

	vector<int> G;

	int from,to;

	for(int i = 0; i < M; i++){

		scanf("%d %d",&from,&to);
		from--;
		to--;
		if(from > to)swap(from,to);

		if(from != 0 && to != N-1)continue;

		if(from == 0){

			G.push_back(to);

		}else{ //to == N-1

			check[from] = true;
		}
	}

	for(int i = 0; i < G.size(); i++){

		if(check[G[i]]){

			printf("POSSIBLE\n");
			return 0;
		}
	}


	printf("IMPOSSIBLE\n");

	return 0;
}
