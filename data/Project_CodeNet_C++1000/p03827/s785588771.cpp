#include<cstdio>
int main()
{
	int n,i,x,max;
	char s[100];
	scanf("%d",&n);
	scanf("%s",s);
	x=0;
	max=0;
	for(i=0;i<n;i++){
		if(s[i]=='I') x+=1;
		else x-=1;
		if(max<x) max=x;
	}
	printf("%d\n",max);
	return 0;
}
