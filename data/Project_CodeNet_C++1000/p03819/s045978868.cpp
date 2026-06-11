#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int maxn=1e5+10;
struct num
{
    int l,r;
} a[3*maxn];
struct node
{
    int l,r,sum,mark;
} tre[maxn<<2];
void build(int l,int r,int rt)
{
    tre[rt].l=l;
    tre[rt].r=r;
    tre[rt].mark=0;
    if(l==r)
    {
        tre[rt].sum=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    tre[rt].sum=tre[rt<<1].sum+tre[rt<<1|1].sum;
    return ;
}
void pushdown(int rt)
{
    if(tre[rt].mark)
    {
        tre[rt<<1].sum+=(tre[rt<<1].r-tre[rt<<1].l+1)*tre[rt].mark;
        tre[rt<<1|1].sum+=(tre[rt<<1|1].r-tre[rt<<1|1].l+1)*tre[rt].mark;
        tre[rt<<1].mark+=tre[rt].mark;
        tre[rt<<1|1].mark+=tre[rt].mark;
        tre[rt].mark=0;
    }
}
void update(int l,int r,int val,int rt)
{
    if(tre[rt].l>=l&&tre[rt].r<=r)
    {
        tre[rt].sum+=(tre[rt].r-tre[rt].l+1)*val;
        tre[rt].mark+=val;
    }
    else
    {
        pushdown(rt);
        int mid=(tre[rt].l+tre[rt].r)>>1;
        if(l>mid) update(l,r,val,rt<<1|1);
        else if(r<=mid) update(l,r,val,rt<<1);
        else
        {
            update(l,r,val,rt<<1);
            update(l,r,val,rt<<1|1);
        }
        tre[rt].sum=tre[rt<<1].sum+tre[rt<<1|1].sum;
    }
}
int query(int pos,int rt)
{
    if(tre[rt].l==pos&&tre[rt].r==pos) return tre[rt].sum;
    else
    {
        pushdown(rt);
        int mid=(tre[rt].l+tre[rt].r)>>1;
        if(pos>mid)return query(pos,rt<<1|1);
        else if(pos<=mid) return query(pos,rt<<1);
    }
}
int n,m;
vector<int>q[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<=m; i++)q[i].clear();
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        q[a[i].r-a[i].l+1].push_back(i);
    }
    build(1,m,1);
    for(int i=1; i<=m; i++)
    {
        int ans=0;
        n-=q[i].size();
        for(int j=0; j<q[i].size(); j++) update(a[q[i][j]].l,a[q[i][j]].r,1,1);
        for(int j=i; j<=m; j+=i) ans+=query(j,1);
        printf("%d\n",ans+n);
    }

}