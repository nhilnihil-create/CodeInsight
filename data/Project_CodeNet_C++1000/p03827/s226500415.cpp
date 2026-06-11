#include<stdio.h>

int main(){

	int n,x=0;
	int max = 0;
	scanf("%d",&n);
	char arr[n];
	
	for(int i=0;i<=n;i++){
		scanf("%c",&arr[i]);
		if(arr[i] == 'I'){
			x++;
		}
		else if(arr[i] == 'D'){
			x--;
		}
		
		
		if(x >= max){
			max = x;
		}
	}

printf("%d",max);

	return 0;
}