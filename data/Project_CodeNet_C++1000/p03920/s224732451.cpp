#include<stdio.h>

	int num[10000000]={0};
int main(void){
	int N;

	scanf("%d",&N);
	int i,j;

	int sum=0;

	for(i=1;sum<N;i++){
		sum += i;
		num[i] = 1;
	}

	i--;

	if(sum==N){
		for(j=1;j<=i;j++){
			printf("%d\n",j);
		}
	}
	else{
		num[sum-N]=0;
		for(j=1;j<=i;j++){
			if(num[j]==1)printf("%d\n",j);
		}
	}
	return 0;
}

