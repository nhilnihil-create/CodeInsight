#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

const int N=1e5+5;
int n,m,nowx,nowy,a[N],ans[N],tmp[N],tl;

int main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i) scanf("%d",&a[i]);
	for(i=1;i<=m;++i)
		if(a[i]&1)
		{
			if(nowy) { printf("Impossible\n"); return 0; }
			if(nowx) nowy=i;
			else nowx=i;
		}
	
	if(!nowy&&!nowx);
	else if(!nowy)
	{
		tl=0;
		for(i=1;i<=m;++i) if(a[i]&1) tmp[++tl]=a[i];
		for(i=1;i<=m;++i) if(!(a[i]&1)) tmp[++tl]=a[i];
		for(i=1;i<=m;++i) a[i]=tmp[i];
	}
	else
	{
		tl=0;
		for(i=1;i<=m;++i) if(a[i]&1) { tmp[++tl]=a[i]; break; }
		for(i=1;i<=m;++i) if(!(a[i]&1)) tmp[++tl]=a[i];
		for(i=m;i;--i) if(a[i]&1) { tmp[++tl]=a[i]; break; }
		for(i=1;i<=m;++i) a[i]=tmp[i];
	}
	
	if(m==1)
	{
		printf("%d\n",a[1]);
		if(a[1]>1)
		{
			printf("2\n");
			printf("%d %d\n",1,a[1]-1);
		}
		else
		{
			printf("1\n");
			printf("%d\n",a[1]);
		}
		return 0;
	}
	
	tl=0;
	for(i=1;i<=m;++i) printf("%d ",a[i]);printf("\n");
	if(a[1]>1) ans[++tl]=a[1]-1;
	for(i=2;i<m;++i) ans[++tl]=a[i];
	ans[++tl]=a[m]+1;
	
	printf("%d\n",tl);
	for(i=1;i<=tl;++i) printf("%d ",ans[i]);printf("\n");
	return 0;
}