#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	int sx,sy,tx,ty;
	scanf("%d %d %d %d",&sx,&sy,&tx,&ty);

	for(int i = 0; i < ty-sy; i++){
		printf("U");
	}
	for(int i = 0; i < tx-sx; i++){

		printf("R");
	}
	for(int i = 0; i < ty-sy; i++){

		printf("D");
	}
	for(int i = 0; i < tx-sx; i++){

		printf("L");
	}
	printf("L");

	for(int i = 0; i < ty-sy+1; i++){

		printf("U");
	}
	for(int i = 0; i < tx-sx+1; i++){

		printf("R");
	}
	printf("D");
	printf("R");

	for(int i = 0; i < ty-sy+1; i++){

		printf("D");
	}
	for(int i = 0; i < tx-sx+1; i++){

		printf("L");
	}
	printf("U\n");

	return 0;
}
