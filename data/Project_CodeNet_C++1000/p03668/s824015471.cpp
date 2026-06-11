#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,x,y,fa[N];
int fst[N],nxt[N*2],to[N*2],l;
void link(int x,int y)
{
	to[++l]=y;nxt[l]=fst[x];fst[x]=l;
	to[++l]=x;nxt[l]=fst[y];fst[y]=l;
}
int Get(int x)
{
	int now=0;
	for (int i=fst[x];i;i=nxt[i])
		if (to[i]!=fa[x])
		{
			fa[to[i]]=x;
			now^=Get(to[i])+1;
		}
	return now;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		link(x,y);
	}
	puts(Get(1)?"Alice":"Bob");
}