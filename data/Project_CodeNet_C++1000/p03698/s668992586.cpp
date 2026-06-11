#include<stdio.h>
int main()
{
	char st[27];
	while(~scanf("%s", st))
	{
		int a[27]={0},i=-1, flag = 0;
		while(st[++i] != 0)
		{
			if(a[st[i]-97])
			{
				flag=1;
				break;
			}
			else a[st[i]-97]++;
		}
		if(flag)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}