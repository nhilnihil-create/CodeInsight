#include<stdio.h>
int main(){
	int a, c=0, max=0;
	scanf("%d", &a);
	char b[a+1];
	scanf("%s", b);
	for(int i=0; b[i]!='\0'; i++){
		if(b[i]== 'D'){
			c--;
		}
		else if(b[i]=='I'){
			c++;
		}
		if(max<c){
			max=c;
		}
	}
	printf ("%d\n", max);
	return 0;
}