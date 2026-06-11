#include<stdio.h>
#include<string.h>

typedef long long ll;			//ld.
typedef unsigned long long ull;	//llu.


int main(){
	char a[15];
	char b[15];
	char c[15];
	scanf("%s %s %s",a,b,c);
	int ada = 0;
	if(a[strlen(a)-1]==b[0]&&b[strlen(b)-1]==c[0])
		ada=1;
	if(ada==1)
		printf("YES\n");
	else
		printf("NO\n");
}
