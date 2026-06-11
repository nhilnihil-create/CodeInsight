#include<stdio.h>

int main()
{
	int x, n, m;
	
	scanf("%d %d %d", &x, &n, &m);
	
	int sum1 = n - x;
	int sum2 = m - x;
	
	if(sum1 < 0){
		sum1 *= -1;
	}
	if(sum2 < 0){
		sum2 *= -1;
	}
	
	if(sum1 < sum2){
		printf("A\n");
	}else{
		printf("B\n");
	}

}