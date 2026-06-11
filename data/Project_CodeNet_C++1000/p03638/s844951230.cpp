#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 105

enum DIR{
	North,
	East,
	South,
	West,
};

struct Info{
	bool operator<(const struct Info &arg) const{

		return num > arg.num;
	}

	int color,num;
};

int N,H,W;
int table[SIZE][SIZE];
Info info[SIZE*SIZE];


int main(){

	scanf("%d %d",&H,&W);
	scanf("%d",&N);

	for(int i = 0; i < H; i++){
		for(int k = 0; k < W; k++){

			table[i][k] = -1;
		}
	}

	for(int i = 0; i < N; i++){

		info[i].color = i+1;
		scanf("%d",&info[i].num);
	}
	sort(info,info+N);


	int row = 0,col = 0;
	DIR dir = South;

	for(int i = 0; i < N; i++){
		//printf("info[%d].color:%d num:%d\n",i,info[i].color,info[i].num);
		for(int k = 0; k < info[i].num; k++){
			//printf("row:%d col:%d color:%d\n",row,col,info[i].color);
			table[row][col] = info[i].color;

			switch(dir){
			case North:
				if(row == 0 || table[row-1][col] != -1){

					col--;
					dir = West;

				}else{

					row--;
				}
				break;
			case East:
				if(col == W-1 || table[row][col+1] != -1){

					row--;
					dir = North;
				}else{

					col++;
				}
				break;
			case South:
				if(row == H-1 || table[row+1][col] != -1){

					col++;
					dir = East;
				}else{

					row++;;
				}
				break;
			case West:
				if(col == 0 || table[row][col-1] != -1){

					row++;
					dir = South;
				}else{

					col--;
				}
				break;
			}
		}
	}

	for(row = 0; row < H; row++){

		printf("%d",table[row][0]);
		for(col = 1; col < W; col++){

			printf(" %d",table[row][col]);
		}
		printf("\n");
	}

	return 0;
}
