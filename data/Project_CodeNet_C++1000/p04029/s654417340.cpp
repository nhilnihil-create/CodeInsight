#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int tot=0;
	for (int i=1; i<=n; i++){
		tot+=i;
	}
	printf("%d\n", tot);
	return 0;
}