#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,a[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

bool solve()
{
	for (int i=1;i<=n;i++)
		if (a[i]&1)
		{
			if (a[i]==1) return 0;
			a[i]--;break;
		}
	int d=a[1],tot=0;
	for (int i=2;i<=n;i++) d=gcd(d,a[i]);
	for (int i=1;i<=n;i++) a[i]/=d,tot+=!(a[i]&1);
	if (tot&1) return 0;
	else if (n-tot>1) return 1;
	else return solve()^1;
}

int main()
{
	n=read();
	int tot=0;
	for (int i=1;i<=n;i++) a[i]=read(),tot+=!(a[i]&1);
	if (tot&1) puts("First");
	else if (n-tot>1) puts("Second");
	else puts(solve()?"First":"Second");
	return 0;
}