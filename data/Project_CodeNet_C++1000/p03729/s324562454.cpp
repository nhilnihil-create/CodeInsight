#include <stdio.h>
#include <string.h>
int main (){
	char a[20],b[20],c[20];
scanf("%s %s %s",&a,&b,&c);
	int lenX=strlen(a);
	int lenY=strlen(b);
	
	if (a[lenX-1]== b[0]&&b[lenY-1]==c[0]){
		puts("YES");
	}else {
		puts("NO");
	}

return 0;

}