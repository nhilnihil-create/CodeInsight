#include<stdio.h>

int main(){
	
	int n,k,x,y;
	
	scanf("%d %d %d %d", &n, &k, &x, &y);
	
	int total = 0;
	
	while(n--){
		if(k > 0){
			total += x;	
		}
		else{
			total += y;
		}
		k--;
	}
	
	printf("%d\n", total);
	
	return 0;
}