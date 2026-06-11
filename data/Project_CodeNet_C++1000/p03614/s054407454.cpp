#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int main()
{
	scanf("%d",&n);
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==i)
			cnt++;
		else
		{
			ans+=(cnt+1)/2;
			cnt=0;
		}
	}
	ans+=(cnt+1)/2;
	printf("%d\n",ans);
}
