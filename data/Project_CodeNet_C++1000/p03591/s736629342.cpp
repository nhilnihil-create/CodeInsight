#include<iostream>
#include<cstdio>
using namespace std;

char ss[1010];

int main(){
	scanf("%s",ss);
	if(ss[0]=='Y'&&ss[1]=='A'&&ss[2]=='K'&&ss[3]=='I')
		printf("Yes");
	else printf("No");
	printf("\n");
	return 0;
}