#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int nowp,ans[10000];
char ch;
bool check(int x)
{
	printf("? ");
	for(int i=1;i<nowp;++i)
		printf("%d",ans[i]);
	printf("%d",x);
	for(int i=1;i<=12-nowp;++i)
		printf("0");
	printf("\n");
	fflush(stdout);
	while(ch=getchar(),ch!='Y'&&ch!='N');
	if(ch=='Y') return 1;
	else return 0;
}
bool check2()
{
	printf("? ");
	for(int i=1;i<=nowp;++i)
		printf("%d",ans[i]);
	printf("\n");
	fflush(stdout);
	while(ch=getchar(),ch!='Y'&&ch!='N');
	if(ch=='Y') 
	{
		if(ans[nowp]!=9)
			return 1;
		else
		{
			printf("? ");
			for(int i=1;i<=nowp;++i)
				printf("%d",ans[i]);
			for(int i=1;i<=12-nowp;++i)
				printf("0");
			printf("\n");
			fflush(stdout);
			while(ch=getchar(),ch!='Y'&&ch!='N');
			if(ch=='Y') return 1;
			else 
			{
				ans[nowp]++;
				return 0;
			}
		}
	}
	else return 0;
	
}
bool check3(int x,int p)
{
	printf("? ");
	for(int i=1;i<nowp;++i)
		printf("%d",ans[i]);
	printf("%d",x);
	for(int i=1;i<=p;++i)
		printf("0");
	printf("\n");
	fflush(stdout);
	while(ch=getchar(),ch!='Y'&&ch!='N');
	if(ch=='Y') return 1;
	else return 0;
	
}
int main()
{
	nowp=1;
	while(1)
	{
		int l=-1,r=9;
		if(nowp==1) l=0;
		while(l<r-1)
		{
			int mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid;
		}
		ans[nowp]=r;
			if(check2())
			{
				if(ans[nowp]<9)
				{
					int t=ans[nowp]+1;
					int now=0;
					while(1)
					{
						if(check3(t,now))
						{
							nowp+=now;
							break;
						}
						now++;
					}
				}
				else
				{
					int t=1;
					int now=1;	
					while(1)
					{
					if(!check3(t,now))
						{
							nowp+=(now-1);
							break;
						}
						now++;
					}
				}
				break;
			}
			else
			{
				ans[nowp]--;
			}
		nowp++;
	}
	printf("! ");
	for(int i=1;i<=nowp;++i)printf("%d",ans[i]);
	return 0;
}