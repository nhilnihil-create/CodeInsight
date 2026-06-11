#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int maxm = 2e5+10;
typedef long long LL;
LL A[maxn]; int n, edgecnt, head[maxn];
struct edge{int v, nxt;} E[maxm];
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
    return x * f;
}
inline void addedge(int u, int v)
{
    E[++edgecnt].v = v, E[edgecnt].nxt = head[u], head[u] = edgecnt;
    E[++edgecnt].v = u, E[edgecnt].nxt = head[v], head[v] = edgecnt;
}
LL dfs(int u, int fa)
{
    int cnt = 0;
    for(int i = head[u]; ~i; i = E[i].nxt)
        if(u != E[i].v && fa != E[i].v) cnt++;
    if(!cnt)
        return A[u];
    LL tot = 0, x1 = 0, x2 = 0, maxw = 0, sumw;
    for(int i = head[u]; ~i; i = E[i].nxt){
        int v = E[i].v;
        if(v == fa) continue;
        sumw = dfs(v, u);
        maxw = max(maxw, sumw);
        tot += sumw;
    }
    x2 = tot - A[u];
    x1 = A[u] - x2;
    if(x1 < 0 || x2 < 0 || A[u] < maxw || (x1 > 0 && fa == -1))
    {
        puts("NO");
        exit(0);
    }
    return x1;
}
int main(){
    memset(head,-1,sizeof head);
    n = read();
    for(int i = 1; i <= n; i++)
        scanf("%lld", &A[i]);
    for(int i = 1; i < n; i++)
        addedge(read(),read());
    if(n == 2)
        if(A[1] == A[2])
            printf("YES\n");
        else
            printf("NO\n");
    else
    {
        for(int i = 1; i <= n; i++)
        {
            int num = 0;
            for(int j = head[i]; ~j; j = E[j].nxt)
                if(E[j].v != i)
                    num++;
            if(num > 1){
                dfs(i, -1);
                break;
            }
        }
        printf("YES\n");
    }
    return 0;
}