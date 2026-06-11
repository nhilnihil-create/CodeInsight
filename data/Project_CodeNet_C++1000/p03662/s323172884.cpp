#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int n;
struct node{
	int y,next;
}a[200010];int len=0,last[100010];
int tot[100010],sta[100010],top=0;
void ins(int x,int y)
{
	a[++len].y=y;
	a[len].next=last[x];last[x]=len;
}
int X;
void dfs(int x,int fa)
{
	sta[++top]=x;tot[x]=1;
	if(n==x) X=sta[(top+1)/2+1];
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa) continue;
		dfs(y,x);tot[x]+=tot[y];
	}
	top--;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d %d",&x,&y);
		ins(x,y);ins(y,x);
	}
	dfs(1,0);
	int s1=n-tot[X],s2=tot[X];
	if(s1>s2) printf("Fennec");
	else printf("Snuke");
}