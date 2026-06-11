#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	char str[n];
	getchar();
	int x = 0;
	int max = 0;
	for(int i = 0; i < n; i++){
		scanf("%c", &str[i]);
		if(str[i] == 'D'){
			x--;
		} else{
			x++;
		}
		if(x > max){
			max = x;
		}
	}
	printf("%d", max);
	return 0;
}