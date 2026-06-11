#include<bits/stdc++.h>
using namespace std;

int n,x;
int a[300000];
map<int,bool> mp;

main()
{
	scanf("%d %d",&n,&x);
	if(x==1||x==2*n-1)
	{
		printf("No");
		return 0;
	}
	printf("Yes\n");
	if(n==2)
	{
		printf("1\n2\n3");
		return 0;
	}
	if(2*n-1-1>x)
	{
		a[n]=x;
		mp[x]=1;
		a[n-1]=x+2;
		mp[x+2]=1;
		a[n+1]=x-1;
		mp[x-1]=1;
		a[n+2]=x+1;
		mp[x+1]=1;
		int nw=1;
		for(int i=1;i<=2*n-1;i++)
		{
			if(a[i]==0)
			{
				while(mp[nw]==1)
				{
					nw++;
				}
				printf("%d\n",nw);
				mp[nw]=1;
			}
			else
			{
				printf("%d\n",a[i]);
			}
		}
	}
	else
	{
		a[n]=x;
		mp[x]=1;
		a[n-1]=x-1;
		mp[x-1]=1;
		a[n+1]=x+1;
		mp[x+1]=1;
		a[n+2]=x-2;
		mp[x-2]=1;
		int nw=1;
		for(int i=1;i<=2*n-1;i++)
		{
			if(a[i]==0)
			{
				while(mp[nw]==1)
				{
					nw++;
				}
				printf("%d\n",nw);
				mp[nw]=1;
			}
			else
			{
				printf("%d\n",a[i]);
			}
		}
	}
}
