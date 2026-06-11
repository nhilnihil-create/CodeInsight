#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int x[100010],xx[100010],w[100010];
int l,r,s,t,n,m;
ll c;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();l=rd();t=rd();
	for (int i=1;i<=n;i++) x[i]=rd(),w[i]=rd();
	for (int i=1;i<=n;i++)
	{
		if (w[i]==2) w[i]=-1;
		r=x[i]+w[i]*t;
		if (r>0) (c+=r/l)%=n;
		else if (r<0) (c+=(r+1)/l-1)%=n;
		xx[i]=(r%l+l)%l;
	}
	sort(xx+1,xx+n+1);
	c=(c+n)%n;
	for (int i=c+1;i<=n;i++) printf("%d\n",xx[i]);
	for (int i=1;i<=c;i++) printf("%d\n",xx[i]);
	return 0;
}