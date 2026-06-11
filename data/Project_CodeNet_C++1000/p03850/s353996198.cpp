#include<cstdio>
#include<iostream>
#include<cstring>
#define ll long long
#define maxn 100010
using namespace std;
int n,i;
ll a[maxn],b[maxn],f[maxn][3];
int read()
{
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
char readch()
{
	char c=getchar();
	while(c!='-'&&c!='+')c=getchar();
	return c;
}
int main()
{
	n=read();
	a[1]=read();
	for(i=2;i<=n;i++)
	{
		if(readch()=='-')b[i]=-1;else b[i]=1;
		a[i]=read();
	}
	memset(f,-0x3f,sizeof(f));
	f[1][0]=a[1];
	for(i=2;i<=n;i++)
	{
		f[i][0]=max(f[i-1][0]+b[i]*a[i],f[i-1][1]-b[i]*a[i]);
		f[i][1]=max(f[i-1][1]-b[i]*a[i],f[i-1][2]+b[i]*a[i]);
		if(b[i]==-1)f[i][1]=max(f[i][1],f[i-1][0]+b[i]*a[i]);
		f[i][2]=f[i-1][2]+b[i]*a[i];
		if(b[i]==-1)f[i][2]=max(f[i][2],f[i-1][1]-b[i]*a[i]);
	}
	printf("%lld\n",f[n][0]);
}