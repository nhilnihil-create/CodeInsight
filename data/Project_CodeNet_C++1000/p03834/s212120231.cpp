#include <stdio.h>

int main(){
char a[101];
int k=101;
scanf("%s",&a);

for (int i=0;i<k;i++){
	if(a[i]==','){
		a[i]=' ';
	}
}
	printf("%s",a);
	puts("");
return 0;	
}
