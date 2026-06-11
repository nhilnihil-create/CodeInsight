#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+3;
int n,cnt,tot,sum1,sum2;
int head[maxn],fa[maxn],siz[maxn];

struct EDGE{
    int next;
    int to;
};
EDGE edge[maxn];

void add(int u,int v)
{
    edge[++cnt].next=head[u];
    edge[cnt].to=v;
    head[u]=cnt;
}

void dfs(int u,int f)
{
    int i,v;
    fa[u]=f;
    siz[u]=1;
    for(int i=head[u];~i;i=edge[i].next)
    {
        v=edge[i].to;
        if(v!=f)
        {
            dfs(v,u);
            siz[u]+=siz[v];
        }
    }
}

int main()
{
    memset(head,-1,sizeof(head));
    int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	//printf("1\n");
	i=n;
	tot=0;
	while(fa[i]!=1)i=fa[i],tot++;
	x=n;
	for(int i=1;i<=tot/2;i++)
        x=fa[x];
    y=x;
    if(y==n)
    {
        sum1=siz[y];
        sum2=n-sum1;
        if(sum2>sum1)
        cout<<"Fennec";
	else cout<<"Snuke";
            return 0;
    }
    y=fa[y];
	dfs(n,0);
	sum1=siz[y];
	sum2=n-sum1;
	if(sum1>sum2)cout<<"Fennec";
	else cout<<"Snuke";

}
