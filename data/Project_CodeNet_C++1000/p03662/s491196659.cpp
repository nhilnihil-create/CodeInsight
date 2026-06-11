#include<iostream>
#include<algorithm>
#include<string>
#include<map>//int dx[4]={0,0,-1,1};int dy[4]={-1,1,0,0};
#include<queue>//int gcd(int a,int b){return b?gcd(b,a%b):a;}
#include<vector>
#include<cmath>
#include<stack>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
#define ll long long
#define maxn 100005
#define eps 0.0000001
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000") ///在c++中是防止暴栈用的
struct eg
{
    int e,next;
    eg (int x=0,int y=0)
    {
        e=x;
        next=y;
    }
}edge[maxn<<1];

int head[maxn];
int tot,a,b;
int d1[maxn],dn[maxn];

void init()
{
    memset(d1,0xf,sizeof(d1));
    memset(dn,0xf,sizeof(dn));
    memset(head,-1,sizeof(head));
    tot=0;
}

void add_edge(int a,int b)
{
    edge[tot]=eg(b,head[a]);
    head[a]=tot++;
}

struct node
{
    int u,d;
    node(int x=0,int y=0)
    {
        u=x;
        d=y;
    }
};

void Bfs(int u)
{
    int vis[maxn];
    memset(vis,0,sizeof(vis));
    vis[u]=1;
    if(u==1) d1[u]=0;
    else dn[u]=0;

    queue<node> q;
    q.push(node(u,0));
    while(!q.empty())
    {
        node tp=q.front();
        q.pop();
        for(int i=head[tp.u];i!=-1;i=edge[i].next)
        {
            int p=edge[i].e;
            if(vis[p]) continue;
            vis[p]=1;
            if(u==1) d1[p]=min(d1[p],tp.d+1);
            else dn[p]=min(dn[p],tp.d+1);
            q.push(node(p,tp.d+1));
        }
    }
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        add_edge(a,b);
        add_edge(b,a);
    }
    Bfs(n);
    Bfs(1);

    ///for(int i=1;i<=n;i++) cout<<d1[i]<<" ";puts("");
    ///for(int i=1;i<=n;i++) cout<<dn[i]<<" ";puts("");

    int cnt1=0,cntn=0;
    for(int i=1;i<=n;i++)
    {
        if(d1[i]<=dn[i]) cnt1++;
        else cntn++;
    }
    if(cnt1<=cntn) puts("Snuke");
    else puts("Fennec");

    return 0;
}
