#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 105

int H,W;
char input[SIZE][SIZE],table[SIZE][SIZE];


int main(){

	scanf("%d %d",&H,&W);

	for(int row = 0; row < H; row++){

		scanf("%s",input[row]);
	}

	for(int row = 0; row <= H+1; row++){
		for(int col = 0; col <= W+1; col++){

			table[row][col] = '#';
		}
	}

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){

			table[row+1][col+1] = input[row][col];
		}
	}

	for(int row = 0; row <= H+1; row++){
		for(int col = 0; col <= W+1; col++){
			printf("%c",table[row][col]);
		}
		printf("\n");
	}


	return 0;
}
