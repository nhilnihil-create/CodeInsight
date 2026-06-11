#include<iostream>
#include<cstdio>
#define N (100000+1000)
using namespace std;

int a[N],b[N],cnt,n,m;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; ++i)
	{
		scanf("%d",&a[i]);
		if (a[i]%2) b[++cnt]=i;
	}
	if (cnt>2) {puts("Impossible"); return 0;}
	if (m==1)
	{
		if (a[1]==1) printf("1\n1\n1\n");
		else printf("%d\n2\n1 %d\n",a[1],a[1]-1);
		return 0;
	}
	if (b[1]) swap(a[1],a[b[1]]);
	if (b[2]) swap(a[m],a[b[2]]);
	
	for (int i=1; i<=m; ++i)
		printf("%d%c",a[i]," \n"[i==m]);
	a[1]++; a[m]--;
	printf("%d\n",a[m]==0?m-1:m);
	for (int i=1; i<=m; ++i)
		if (a[i]!=0) printf("%d%c",a[i]," \n"[i==m]);
}