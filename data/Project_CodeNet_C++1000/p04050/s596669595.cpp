#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 20021225
#define ll long long
#define mxn 110
using namespace std;
 
int n,a[mxn],m;
 
int main()
{
	int cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		cnt+=a[i]%2;
	}
	if(cnt>2)
	{
		printf("Impossible\n");
		return 0;
	}
	int fs=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i]%2==1)
		{
			if(!fs)	swap(a[1],a[i]),fs=1;
			else	swap(a[m],a[i]);
		}
	}
	for(int i=1;i<=m;i++)	printf("%d ",a[i]);puts("");
	if(m==1)
	{
		if(a[1]==1)	printf("1\n1\n");
		else	printf("2\n1 %d\n",a[1]-1);
		return 0;
	}
	a[1]--; a[m]++; 
	if(a[1]==0)
	{
		printf("%d\n",m-1);
		for(int i=2;i<=m;i++)	printf("%d ",a[i]);
	}
	else
	{
		printf("%d\n",m);
		for(int i=1;i<=m;i++)	printf("%d ",a[i]);
	}
	return 0;
}
