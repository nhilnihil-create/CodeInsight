#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int nmax=100005;
vector<int> v[nmax];
int d[nmax],nxt[nmax],dpth[nmax],viz[nmax],cyc[nmax];
int n,k,cate,i,x,nr;
void recu(int x)
{
    if(x==1) return;
    if(d[x]) return;
    recu(nxt[x]);
    d[x]=d[nxt[x]]+1;
    v[nxt[x]].push_back(x);
}
void dfs(int x)
{
    dpth[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i]);
        dpth[x]=max(dpth[x],dpth[v[x][i]]+1);
    }
    if(dpth[x]==k&&nxt[x]!=1)
        dpth[x]=0,cate+=1;
}
int solve()
{
    int ret=0;
    if(nxt[1]!=1) ret++,nxt[1]=1;
    if(k==1)
    {
        for(i=2;i<=n;i++)
            ret+=(nxt[i]!=1);
        return ret;
    }
    dfs(1);
    ret+=cate;
    return ret;
}
int main()
{
    //freopen("data.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>nxt[i];
    int x=i;
    while(!viz[x])
    {
        viz[x]=1;
        cyc[++nr]=x;
        x=nxt[x];
    }
    for(i=2;i<=nr;i++)
    {
        v[cyc[i-1]].push_back(cyc[i]);
        d[cyc[i]]=nr+1-i;
    }
    for(i=2;i<=n;i++)
        if(!d[i])
            recu(i);
    cout<<solve();
    return 0;
}