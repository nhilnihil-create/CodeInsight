#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 55

int N,M;
char A[SIZE][SIZE],B[SIZE][SIZE];


int main(){

	scanf("%d %d",&N,&M);

	for(int row = 0; row < N; row++){

		scanf("%s",A[row]);
	}
	for(int row = 0; row < M; row++){

		scanf("%s",B[row]);
	}

	bool FLG;
	for(int base_row = 0; base_row+M <= N; base_row++){
		for(int base_col = 0; base_col+M <= N; base_col++){

			FLG = true;
			for(int row = 0; row < M; row++){
				for(int col = 0; col < M; col++){
					if(A[base_row+row][base_col+col] != B[row][col]){
						FLG = false;
						break;
					}
				}
				if(!FLG)break;
			}


			if(FLG){
				printf("Yes\n");
				return 0;
			}
		}
	}



	printf("No\n");

	return 0;
}
