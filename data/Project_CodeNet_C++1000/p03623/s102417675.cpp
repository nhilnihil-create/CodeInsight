#include<stdio.h>
#include<math.h>
int main(){
	int home,a,b;
	scanf("%d%d%d",&home,&a,&b);
	if(abs(home - a ) < abs(home - b)) printf("A\n");
	else printf("B\n");
	
	
	
 	return 0;
}