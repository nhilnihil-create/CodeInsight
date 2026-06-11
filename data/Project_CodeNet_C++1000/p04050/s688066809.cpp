#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#define N 110
using namespace std;
int n,m,a[N],b[N],bl;
int main()
{
	scanf("%d%d",&n,&m);
	int t=0;
	for(int i=1;i<=m;i++) 
	{
		scanf("%d",&a[i]);
		if(a[i]%2) t++;
	}
	if(m==1)
	{
		if(a[1]>1) b[++bl]=a[1]-1;
		b[++bl]=1;
		printf("%d\n%d\n",a[1],bl);
		for(int i=1;i<=bl;i++) printf("%d ",b[i]);
		return 0;
	}
	if(t>2) {printf("Impossible\n");return 0;}
	for(int i=1;i<=m;i++) if(a[i]%2) {swap(a[i],a[1]);break;}
	for(int i=2;i<=m;i++) if(a[i]%2) {swap(a[i],a[m]);break;}
	if(a[1]>1) b[++bl]=a[1]-1;
	for(int i=2;i<m;i++) b[++bl]=a[i];
	b[++bl]=a[m]+1;
	for(int i=1;i<=m;i++) printf("%d ",a[i]);printf("\n");
	printf("%d\n",bl);
	for(int i=1;i<=bl;i++) printf("%d ",b[i]);
	return 0;
}