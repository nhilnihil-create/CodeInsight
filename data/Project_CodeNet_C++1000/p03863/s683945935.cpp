#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
int main(){
	int n;
	char a[100005];
	scanf("%s",a+1);
	n=strlen(a+1);
	if((a[1]==a[n]&&n%2==1)||(a[1]!=a[n]&&n%2!=1))printf("Second\n");
	else printf("First\n");
	return 0;
}
