#include<stdio.h>
int main (){
	int n;
	int hasil= 0;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		hasil +=i;	
	}
	printf("%d", hasil);
	
}