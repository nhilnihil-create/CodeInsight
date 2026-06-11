#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

int a[305];
LL bin[55],n;

int main()
{
	scanf("%lld",&n);
	bin[0]=1;
	for (int i=1;i<=50;i++) bin[i]=bin[i-1]*2;
	int m=50;
	while (bin[m]>n) m--;
	int tot=0,p=m+1;
	for (int i=1;i<=m;i++) a[++tot]=i;
	for (int i=1;i<=m;i++) a[++tot]=i;
	a[++tot]=m+1;a[++tot]=m+1;
	for (int i=m-1;i>=0;i--)
		if (n&bin[i])
		{
			tot++;
			for (int j=tot;j>i+1;j--) a[j]=a[j-1];
			p++;a[i+1]=a[++tot]=p;
		}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d ",a[i]);
	return 0;
}