#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



struct LOC{

	int x,y;
};


int N,M;
LOC from[55],to[55];


int main(){

	scanf("%d %d",&N,&M);

	for(int i = 0; i < N; i++){

		scanf("%d %d",&from[i].x,&from[i].y);
	}
	for(int i = 0; i < M; i++){

		scanf("%d %d",&to[i].x,&to[i].y);
	}

	for(int i = 0; i < N; i++){
		int min_dist = BIG_NUM;
		int index;

		for(int k = 0; k < M; k++){

			int tmp = abs(from[i].x-to[k].x)+abs(from[i].y-to[k].y);

			if(tmp < min_dist){
				min_dist = tmp;
				index = k;
			}
		}
		printf("%d\n",index+1);
	}

	return 0;
}
