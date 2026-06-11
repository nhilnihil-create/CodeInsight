#include <stdio.h>
#include <string.h>

int main(){
	int Kids, i=1, Candies=0;
	scanf ("%d", &Kids);
	
	while (i<=Kids){
		Candies+=i;
		i++;
	}
	printf("%d", Candies);
	return 0;
}