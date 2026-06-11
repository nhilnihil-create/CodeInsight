//此程序使用了qt专属名称，请勿模仿。侵权必究！！！
//我真是太菜了啊……
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
const ll N=100010;
int n,m,q,t=0,f[N][20];
vector<int> a[N];
bool vis[N];
int v[N],d[N],c[N];
inline int read()
{
	int sum=0,flag=1;
	char c;
	for(;c<'0'||c>'9';c=getchar())if(c=='-') flag=-1;
	for(;c>='0'&&c<='9';c=getchar())sum=(sum<<1)+(sum<<3)+c-'0';
	return sum*flag;
}
inline void dfs(int x,int y,int z)
{
	if(y<0)
	{
		return;
	}
	if(f[x][y])
	{
		return;
	}
	f[x][y]=z;
	for(int i=a[x].size()-1;i>=0;--i)
	{
		dfs(a[x][i],y-1,z);
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=n;++i)
	{
		a[i].push_back(i);
	}
	q=read();
	for(int i=1;i<=q;++i)
	{
		v[i]=read();
		d[i]=read();
		c[i]=read();
	}
	for(int i=q;i;--i)
	{
		dfs(v[i],d[i],c[i]);
	}
	for(int i=1;i<=n;++i)
	{
		printf("%d\n",f[i][0]);
	}
	return 0;
}