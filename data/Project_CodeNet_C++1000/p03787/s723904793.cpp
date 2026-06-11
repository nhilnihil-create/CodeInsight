#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define debug(a) cout<<a<<endl
#define clr(a) memset(a,0,sizeof(a))
#define clrne(a) memset(a,-1,sizeof(a))
#define clrinf(a) memset(a,0x3f,sizeof(a))
#define clrneinf(a) memset(a,0xc0,sizeof(a))
#define pb(a) push_back(a)
#define maxn 10001
#define mod 1000000007
#define eps 1e-9
#define inf 0x7fffffff
struct e
{
    int next;
    int to;
};
e E[200010<<1];
int head[100010];
int vis[100010];
int cl[100010];
int tot;
void init()
{
    tot = 0;
    clrne(head);
    clr(vis);
}
void addedge(int u,int v)
{
    E[tot].to = v;
    E[tot].next = head[u];
    head[u] = tot++;
}
queue <int> q;
int main()
{
//  freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    for (int i = 0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    ll I,P,Q;
    I = P = Q = 0;
    for (int i = 1;i<=n;i++)
    {
        if (!vis[i])
        {
            if (head[i]==-1)
            {
                vis[i] = 1;
                I++;
                continue;
            }
            while (!q.empty()) q.pop();
            bool ok = 1;
            cl[i] = 0;
            vis[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int j = head[u];j!=-1;j = E[j].next)
                {
                    int v = E[j].to;
                    if (!vis[v])
                    {
                        vis[v] = 1;
                        q.push(v);
                        cl[v] = cl[u] +1;
                        cl[v]&=1;
                    }
                    else
                    {
                        if ((cl[u]^cl[v])!=1) ok = false;
                    }
                }
            }
//            cout<<cl[1]<<' '<<cl[2]<<endl;
//            if (!ok)cout<<i<<endl;
            if (ok) Q++;
            else P++;
        }
    }
//    cout<<I<<' '<<P<<' '<<Q<<endl;
//    Q = 1;
    ll ans = 2*I*n - I*I +P*P + 2*P*Q + 2*Q*Q;
    printf("%lld\n",ans);
    return 0;
}
