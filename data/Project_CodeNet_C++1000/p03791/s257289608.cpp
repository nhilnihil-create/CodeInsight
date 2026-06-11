#include<stdio.h>

long long N,r[100006];
long long sum=1;

int main(){
	scanf("%lld",&N);
	for(int i=0;i<N;i++){
		scanf("%lld",&r[i]);
	}
	
	int j=0;
	for(int i=0;i<N;i++){
		for(j;j<N&&2*(j-i)<r[j];j++);
		if(j<N)j++;
		sum*=(j-i);
		sum%=1000000007;
	}
	printf("%lld",sum);
	
	return 0;
}