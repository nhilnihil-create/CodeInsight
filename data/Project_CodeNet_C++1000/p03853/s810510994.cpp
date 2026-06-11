#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int H,W;
char buf[105][105];

int main(){

	scanf("%d %d",&H,&W);

	for(int row = 0; row < H; row++){

		scanf("%s",buf[row]);
	}

	for(int row = 0; row < H; row++){
		for(int i = 0; i < 2; i++){
			for(int col = 0; col < W; col++){

				printf("%c",buf[row][col]);
			}
			printf("\n");
		}
	}

	return 0;
}
