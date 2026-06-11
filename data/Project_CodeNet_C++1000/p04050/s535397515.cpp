#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[110];
int cnt;
int cur=1;
int sw1,sw2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",a+i);
		if(a[i]&1)
		{
			cnt++;
			if(!sw1)sw1=i;
			else sw2=i;
		}
	}
	if(cnt>2)
	{
		printf("Impossible");
		return 0;
	}
	if(sw1)swap(a[1],a[sw1]);
	if(sw2)swap(a[m],a[sw2]);
	for(int i=1;i<=m;i++)printf("%d ",a[i]);
	puts("");
	m=max(m,2);
	a[1]--;a[m]++;
	int st=1;
	if(!a[1])st=2;
	printf("%d\n",m+1-st);
	for(int i=st;i<=m;i++)printf("%d ",a[i]);
	return 0;
} 