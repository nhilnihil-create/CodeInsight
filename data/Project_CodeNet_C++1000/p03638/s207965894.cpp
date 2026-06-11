#include<stdio.h>

const int maxn = 10005;

int h,w,n;
int A[maxn],B[maxn][maxn];

int main(){
//	freopen("in15.txt","r",stdin);
	scanf("%d%d%d", &h, &w, &n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);//颜色i的数量 
	}
	//h行  w列 
	int index = 0;
	for(int i=1;i<=n;i++){
		//分配颜色
		while(A[i]--){
			//第index个元素
			int c = index-(index/w*w);
			if(index/w%2 == 0){//0 2 4顺着的行 
				B[index/w][c] = i;
			}else{//逆着的行 
				B[index/w][w-1-c] = i;
			} 
			index++; 
		} 	
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(j<w-1){
				printf("%d ",B[i][j]);
			}else{
				printf("%d\n", B[i][j]);
			}
		}
	}
	
	return 0;
}