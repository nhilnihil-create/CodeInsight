#include<bits/stdc++.h>
using namespace std;
int n,a[505],b[505],c[250005];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
void biu()
{
	puts("No");
	exit(0);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=i;c[a[i]]=i;
	}
	sort(b+1,b+n+1,cmp);
	int now=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<b[i];j++)
		{
			while(c[now])now++;
			c[now]=b[i];
		}
		if (now>a[b[i]]) biu();
	}
	now=n*n;
	for (int i=n;i>=1;i--)
	{
		for (int j=b[i]+1;j<=n;j++)
		{
			while(c[now])now--;
			c[now]=b[i];
		}
		if (now<a[b[i]]) biu();
	}
	puts("Yes");
	for (int i=1;i<=n*n;i++)
		printf("%d ",c[i]);
}