#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	char id[n];
	
	int x = 0;
	int max = 0;
	
	scanf("%s", id);
	for(int i = 0; id[i] != '\0'; i++){
		if(id[i] == 'I'){
			x++;
			if(max < x){
				max = x;
			}
		}
		else if(id[i] == 'D'){
			x--;
		}
	}
	printf("%d\n", max);
	return 0;
}