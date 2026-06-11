#include<bits/stdc++.h>
using namespace std;

int R,C,H,W,D;
int A[505][505];
long long Sum;

int main(){
	int i,j;
	scanf("%d%d%d%d",&R,&C,&H,&W);
	D=(H*W>1?999999999/(H*W-1):1000000000);
	for(i=1;i<=R;i++)
		for(j=1;j<=C;j++){
			A[i][j]=(i%H||j%W?D:-(H*W-1)*D-1);
			Sum+=A[i][j];
		}
	if(Sum<=0)
		puts("No");
	else{
		puts("Yes");
		for(i=1;i<=R;i++){
			for(j=1;j<=C;j++)
				printf("%d ",A[i][j]);
			puts("");
		}
	}
	return 0;
}