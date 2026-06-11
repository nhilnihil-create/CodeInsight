#include<bits/stdc++.h>
using namespace std;

int a[100010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++) a[i]=rd();
	if (m==1)
	{
		if (a[1]==1) { puts("1");puts("1");puts("1");return 0; }
		printf("%d\n",a[1]);
		puts("2");
		printf("%d %d\n",1,a[1]-1);
		return 0;
	}
	if (m==2)
	{
		int mm=1;
		if (a[1]>1) mm++;
		if (a[2]>1) mm++;
		printf("%d %d\n",a[1],a[2]);
		printf("%d\n",mm);
		if (a[1]>1) printf("%d ",a[1]-1);
		printf("%d ",2);
		if (a[2]>1) printf("%d\n",a[2]-1);
		else printf("\n");
		return 0;
	}
	int cnt=0;
	for (int i=1;i<=m;i++) if (a[i]&1) cnt++;
	if (cnt>2) { puts("Impossible");return 0; }
	if (cnt==2)
	{
		int h1=0,h2=0;
		for (int i=1;i<=m;i++) if (a[i]&1) { if (!h1) h1=a[i];else h2=a[i]; }
		printf("%d ",h1);
		for (int i=1;i<=m;i++) if (!(a[i]&1)) printf("%d ",a[i]);
		printf("%d\n",h2);
		int mm=m-1;
		if (h1>1) mm++;if (h2>1) mm++;
		printf("%d\n",mm);
		if (h1>1) printf("%d ",h1-1);
		printf("%d ",2);
		for (int i=1;i<=m;i++) if (!(a[i]&1)) printf("%d ",a[i]);
		if (h2>1) printf("%d\n",h2-1);
		else printf("\n");
		return 0;
	}
	if (cnt==1)
	{
		int hh=0;
		for (int i=1;i<=m;i++) if (a[i]&1) hh=a[i];
		for (int i=1;i<=m;i++) if (!(a[i]&1)) printf("%d ",a[i]);
		printf("%d\n",hh);
		int mm=m;
		if (hh>1) mm++;
		printf("%d\n",mm);
		bool flag=false;
		for (int i=1;i<=m;i++)
		{
			if (a[i]&1) continue;
			if (!flag) printf("%d %d ",1,a[i]);
			else printf("%d ",a[i]);
			flag=true;
		}
		if (hh>1) printf("%d\n",hh-1);
		else printf("\n");
		return 0;
	}
	for (int i=1;i<=m;i++) printf("%d ",a[i]);
	puts("");
	int mm=m-1;
	if (a[1]>1) mm++;if (a[m]>1) mm++;
	printf("%d\n",mm);
	if (a[1]>1) printf("%d ",a[1]-1);
	printf("%d ",2);
	for (int i=2;i<m;i++) printf("%d ",a[i]);
	if (a[m]>1) printf("%d\n",a[m]-1);
	else printf("\n");
	return 0;
}