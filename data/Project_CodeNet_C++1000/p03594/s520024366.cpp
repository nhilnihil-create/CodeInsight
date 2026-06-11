#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int h,w,d;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int col[4001][4001];
int ng[501][501];
int ans[501][501];

int main(void){
	scanf("%d%d%d",&h,&w,&d);
	memset(col,-1,sizeof(col));
	for(int i=0;i<2000;i+=d*2){
		for(int j=0;j<2000;j+=d*2){
			for(int k=0;k<d;k++){
				for(int l=0;l<d;l++){
					col[i+k][j+l]=0;
					col[i+k][j+d+l]=1;
					col[i+d+k][j+d+l]=2;
					col[i+d+k][j+l]=3;
				}
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			ans[i][j]=col[500+i+j][500+i-j];
		}
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(ans[i][j]==0)printf("R");
			if(ans[i][j]==1)printf("G");
			if(ans[i][j]==2)printf("B");
			if(ans[i][j]==3)printf("Y");
		}
		printf("\n");
	}
	return 0;
}