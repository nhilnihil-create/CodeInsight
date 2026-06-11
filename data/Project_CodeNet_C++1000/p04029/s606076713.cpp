#include<stdio.h>
int main(){
	int N;
	int result = 0;
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; i++){
		result += i;
	}
	printf("%d\n", result);
	return 0;
}