#include<bits/stdc++.h>
using namespace std;
int main()
{
	int len=0;
	char s[2];
	for(int i=1;i<=9;i++)
	{
		printf("? 1");
		for(int j=1;j<=i;j++)putchar('0');
		puts("");
		fflush(stdout);
		scanf("%s",s);
		if(s[0]=='N')
		{
			len=i;
			break;
		}
	}
	if(!len)
	{
		for(int i=1;i<=10;i++)
		{
			putchar('?');
			putchar(' ');
			for(int j=1;j<=i;j++)
			{
				putchar('9');
			}
			puts("");
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')
			{
				putchar('!');
				putchar(' ');
				putchar('1');
				for(int j=1;j<=i-1;j++)putchar('0');
					puts("");
				fflush(stdout);
				return 0;
			}
		}
	}
	int ans[100];
	for(int i=len;i>=1;i--)
	{
		int l=0,r=9;
		while(l<r)
		{
			if(i==len&&l==0&&r==1)
			{
				break;
			}
			int mid=(l+r)>>1;
			putchar('?');
			putchar(' ');
			for(int k=len;k>i;k--)printf("%d",ans[k]);
			printf("%d" ,mid);
			for(int j=1;j<=12-(len-i);j++)putchar('9');
			puts("");
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='N')
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		ans[i]=r;
	}

	putchar('!');
	putchar(' ');
	for(int j=len;j>=1;j--)
	{
		printf("%d",ans[j]);
	}
	puts("");
	fflush(stdout);
	return 0;
}