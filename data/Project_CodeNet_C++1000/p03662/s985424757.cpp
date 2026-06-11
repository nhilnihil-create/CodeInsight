#include<queue>  
#include<vector>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>
using namespace std;  
const int maxn = 1e5+3;  
int cnt=0, id=0, Next[maxn],in[maxn],out[maxn];  
int fa[maxn][20], len[maxn];  
struct node  
{  
    int v, next;  
}
edge[maxn<<1];  
void add_edge(int u, int v)  
{  
    edge[cnt] = {v, Next[u]};  
    Next[u] = cnt++;  
    edge[cnt] = {u, Next[v]};  
    Next[v] = cnt++;  
}  
void dfs(int cur, int pre, int d)  
{  
    fa[cur][0] = pre;  
    len[cur] = d;  
    for(int i=1; i<20; ++i)  
        fa[cur][i] = fa[fa[cur][i-1]][i-1];  
    in[cur] = ++id;  
    for(int i=Next[cur]; i!=-1; i=edge[i].next)  
    {  
        int v = edge[i].v;  
        if(v == pre) continue;  
        dfs(v, cur, d+1);  
    }  
    out[cur] = id;  
}  
int main()  
{  
    int n, a, b;  
    scanf("%d",&n);  
    memset(Next, -1, sizeof(Next));  
    for(int i=1; i<n; ++i)  
    {  
        scanf("%d%d",&a,&b);  
        add_edge(a, b);  
    }  
    dfs(1, 0, 0);  
    int tmp=(len[n]-1)/2, now=n;  
    for(int i=0; i<20; ++i)  
        if(tmp>>i&1) now = fa[now][i];  
    int bl = n-(out[now]-in[now]+1)-len[n]/2-1;  
    int wh = out[now]-in[now]+1-tmp-1;  
    if(len[n]&1)  
    {  
        if(bl <= wh) puts("Snuke");  
        else puts("Fennec");  
    }  
    else  
    {  
        if(wh <= bl) puts("Fennec");  
        else puts("Snuke");  
    }  
    return 0;  
}   