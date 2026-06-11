#include<stdio.h>
#include<string.h>

int main(){
	
	int arr;
	int flag = 1;
	
	scanf("%d", &arr);
	
	if(arr % 10 == arr/100){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	return 0;
}