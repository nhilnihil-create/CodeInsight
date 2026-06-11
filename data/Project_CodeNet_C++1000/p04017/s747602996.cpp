//此程序使用了qt专属名称，请勿模仿。侵权必究！！！
//我真是太菜了……
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000100;
int n,m,l,k;
int a[N],f[N][30];
inline int read()
{
	int sum=0,flag=1;
	char c;
	for(;c<'0'||c>'9';c=getchar())if(c=='-') flag=-1;
	for(;c>='0'&&c<='9';c=getchar())sum=(sum<<1)+(sum<<3)+c-'0';
	return sum*flag;
}
int main()
{
//	freopen("trav.in","r",stdin);
//	freopen("trav.out","w",stdout);
	n=read();
	k=log2(n)+1;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
	}
	l=read();
	for(int i=1,j=2;i<=n;++i)
	{
		while(j<=n)
		{
			if(a[j]-a[i]<=l)
			{
				++j;
			}
			else
			{
				break;
			}
		}
		f[i][0]=j-1;
	}
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=n;++j)
		{
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
	m=read();
	while(m--)
	{
		int x=read(),y=read(),z=0;
		if(x>y)
		{
			swap(x,y);
		}
		for(int i=k;i>=0;--i)
		{
			if(f[x][i]<y)
			{
				z+=1<<i;
				x=f[x][i];
			}
		}
		printf("%d\n",z+1);
	}
	return 0;
}



