#include <stdio.h>
int main(){
	int n;
	int candies = 0;
	
	scanf("%d", &n);	//children
						//1 candy first line, 2 candy second line, n candy to n line
	for(int i=0; i<=n; i++){	//selama i <= n, i nambah, danutk tiap line, si candy nambah
		candies += i;
	}
	printf("%d", candies);
	
	return 0;
}