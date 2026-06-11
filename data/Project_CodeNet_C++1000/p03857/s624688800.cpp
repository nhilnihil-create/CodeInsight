#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define maxn 200005
using namespace std;

int n,k,l;
int info[maxn],Prev[maxn*2],to[maxn*2],cnt_e,col[2][maxn],c[maxn],siz[maxn],fa[maxn];
inline void Node(const int &u,const int &v){ Prev[++cnt_e]=info[u],info[u]=cnt_e,to[cnt_e]=v; }
void dfs(int now,int c,int typ)
{
    col[typ][now]=c;
    for(int i=info[now];i;i=Prev[i])
        if(!col[typ][to[i]])
            dfs(to[i],c,typ);
}
inline bool cmp(const int &a,const int &b){ return col[0][a]==col[0][b] ? col[1][a]<col[1][b] : col[0][a] < col[0][b]; }

int main()
{
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1,u,v;i<=k;i++)
    {
        scanf("%d%d",&u,&v);
        Node(u,v),Node(v,u);
    }

    for(int i=1;i<=n;i++)
        if(!col[0][i])
            dfs(i,i,0);

    cnt_e=0;
    memset(info,0,sizeof info);
    for(int i=1,u,v;i<=l;i++)
    {
        scanf("%d%d",&u,&v);
        Node(u,v),Node(v,u);
    }


    for(int i=1;i<=n;i++)
        if(!col[1][i])
            dfs(i,i,1);


    for(int i=1;i<=n;i++)
        c[i]=i;

    sort(c+1,c+1+n,cmp);

    for(int i=1;i<=n;i++)
    {
        fa[c[i]]=c[i];
        if(i!=1 && col[0][c[i]] == col[0][c[i-1]] && col[1][c[i]]== col[1][c[i-1]])
            fa[c[i]] = fa[c[i-1]];
        siz[fa[c[i]]]++;
    }

    for(int i=1;i<n;i++) printf("%d ",siz[fa[i]]);
    printf("%d",siz[fa[n]]);
}
