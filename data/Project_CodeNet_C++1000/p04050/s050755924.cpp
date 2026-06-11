#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j,a[105],ans[100005],cnt;
bool cmp(int a,int b)
{
	return a%2<b%2;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d",a+i);
		if(a[i]&1)
			++j;
	}
	if(j>2)
	{
		printf("Impossible");
		return 0;
	}
	sort(a+1,a+1+m,cmp);
	if(m==1)
	{
		if(a[1]==1)
			ans[++cnt]=1;
		else
		{
			ans[++cnt]=1;
			ans[++cnt]=a[1]-1;
		}
	}
	else
	{
		if(a[m-1]&1)
			swap(a[1],a[m-1]);
		if(a[1]&1)
			ans[++cnt]=a[1]+1;
		else
		{
			ans[++cnt]=1;
			ans[++cnt]=a[1];
		}
		for(i=2;i<m;++i)
			ans[++cnt]=a[i];
		if(a[m]!=1)
			ans[++cnt]=a[m]-1;
	}
	for(i=1;i<=m;++i)
		printf("%d ",a[i]);
	puts("");
	printf("%d\n",cnt);
	for(i=1;i<=cnt;++i)
		printf("%d ",ans[i]);
	return 0;
}
