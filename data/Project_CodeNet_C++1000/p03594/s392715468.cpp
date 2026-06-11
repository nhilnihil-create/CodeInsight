#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char C[] = "RYGB";
char A[505][505];

int main()
{
	int H, W, D;
	scanf("%d%d%d", &H, &W, &D);
	if( D%2 == 1 ){
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				printf("%c", C[i%2*2 + j%2]);
			}
			printf("\n");
		}
	}
	else{
		for(int i = -D/2*4; i < H+D/2*10; i += D/2){
			for(int j = -D/2*4; j < W+D/2*10; j += D/2){
				if( (i/(D/2) + j/(D/2) + 20000)%2 == 1 ) continue;
				int v = (i/(D/2) + j/(D/2) + 20000)%4;
				if( i%D ) v |= 1; 
				for(int k = 0; k < D-1; k++){
					for(int l = 0; l < D; l++){
						if( k+l < D/2-1 || k-l < -D/2 || k-l >= D/2 || k+l >= D/2*3-1) continue;
						if( 0 <= i+k && i+k < H && j+l < W && 0 <= j+l ) A[i+k][j+l] = C[v];
					}
				}
			}
		}
		for(int i = 0; i < H; i++) printf("%s\n", A[i]);
	}
	return 0;
}
