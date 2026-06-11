#include<bits/stdc++.h>
using namespace std;

vector<int> v[100010];

int fa[100010],mx[100010],dep[100010],n,m,ans;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void dfs(int x)
{
	mx[x]=0;
	for (int i=0,siz=v[x].size();i<siz;i++)
	{
		int t=v[x][i];
		dep[t]=dep[x]+1;dfs(t);
		mx[x]=max(mx[x],mx[t]+1);
	}
	if (mx[x]==m-1&&dep[x]>1) mx[x]=-1,ans++;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) fa[i]=rd();
	ans=0;
	if (fa[1]!=1) ans++,fa[1]=1;
	for (int i=2;i<=n;i++) v[fa[i]].push_back(i);
	dfs(1);
	printf("%d\n",ans); 
	return 0;
}