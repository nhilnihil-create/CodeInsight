#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,m,a[N],b[N],tot,w[N],top;
int read()
{
	int r=0,f=1;
	char p=getchar();
	while(p>'9'||p<'0')
	{
		if(p=='-')
			f=-1;
		p=getchar();
	}
	while(p>='0'&&p<='9')
	{
		r=r*10+p-48;
		p=getchar();
	}
	return r*f;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		a[i]=read();
		if(a[i]&1)
			w[++top]=i;
	}
	if(top>2)
	{
		puts("Impossible");
		return 0;
	}
	if(top==0)
	{
		b[++tot]=1;
		for(int i=1;i<m;i++)
			b[++tot]=a[i];
		for(int i=1;i<=(a[m]-1)/2/2;i++)
			b[++tot]=2;
		b[++tot]=1;
		for(int i=(a[m]-1)/2/2+1;i<=(a[m]-1)/2;i++)
			b[++tot]=2;
	}
	if(top==1)
	{
		swap(a[w[1]],a[m]);
		b[++tot]=1;
		for(int i=1;i<m;i++)
			b[++tot]=a[i];
		for(int i=1;i<=(a[m]-1)/2;i++)
			b[++tot]=2;
	}
	if(top==2)
	{
		swap(a[w[1]],a[m]);
		swap(a[w[2]],a[1]);
		b[++tot]=a[1]+1;
		for(int i=2;i<m;i++)
			b[++tot]=a[i];
		for(int i=1;i<=(a[m]-1)/2;i++)
			b[++tot]=2;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",a[i]);
	printf("\n%d\n",tot);
	for(int i=1;i<=tot;i++)
		printf("%d ",b[i]);
	return 0;
}