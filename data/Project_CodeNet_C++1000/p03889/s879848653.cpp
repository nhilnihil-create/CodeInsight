#include<cstdio>
#include<cstring>
int main()
{
	int i,n;
	char a[100005],b[100005];
	gets(a);
	n=strlen(a);
	for(i=0;i<n;i++)
	b[n-i-1]=a[i];
	for(i=0;i<n;i++)
	{
		if(b[i]=='b')
		{
			b[i]='d';
			continue;
		}
		if(b[i]=='d')
		{
			b[i]='b';
			continue;
		}
		if(b[i]=='q')
		{
			b[i]='p';
			continue;
		}
		if(b[i]=='p')
		{
			b[i]='q';
			continue;
		}
	}
	b[n]='\0';
	if(strcmp(a,b)==0)
	printf("Yes");
	else
	printf("No");
	return 0;
}