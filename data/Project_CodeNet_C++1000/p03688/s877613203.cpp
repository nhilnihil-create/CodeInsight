#include<bits/stdc++.h>
using namespace std;
int a[1000005],T,n;
bool check(int m,int k)
{
//	cout<<m<<' '<<k<<endl;
	if(k==0)	return false;
	if(m/k>1)	return true;
	return false;
}
int main()
{
//	scanf("%d",&T);
//	while(T--)
	{
		memset(a,0,sizeof(a));
		int maxn=0;
		bool flag=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			maxn=max(maxn,x),a[x]++;
			if(x!=maxn&&x!=maxn-1)	flag=1;
		}
		if(flag)	{printf("No\n");return 0;}
		if(n==1&&a[0]!=1)	{printf("No\n");return 0;}
		if((a[maxn]==n&&maxn==n-1)||(a[maxn]==n&&maxn==1))	{printf("Yes\n");return 0;}
		if(check(n-a[maxn-1],maxn-a[maxn-1]))	{printf("Yes\n");return 0;}
		printf("No\n");
	}
	return 0;
}