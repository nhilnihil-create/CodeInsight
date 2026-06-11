#include <stdio.h>
#include <string.h>
int main(){
char a[101],b[101],c[101],m,n;
scanf ("%s %s %s",&a,&b,&c);
m=strlen(a);
n=strlen(b);
if(a[m-1]==b[0]&&b[n-1]==c[0]){
	printf("YES");
}
else{
	printf("NO");
}
return 0;
}
