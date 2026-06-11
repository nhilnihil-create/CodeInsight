#include <stdio.h>

int main(){
	int n,out=0, max=0;
	char cha[101];
	scanf("%d", &n);
	scanf("%s", cha);
	for(int i = 0; i < n; i++){
		if(cha[i]=='I'){
			out++;
		}else{
			out--;
		}
		if(max<out){
			max=out;
		}
	}
	printf("%d", max);
	
	return 0;
}