#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long LL;
#define M(a,b) memset(a,b,sizeof(a))
#define pb push_back
const int maxn = 100000+10;
const LL mod = 1000000007;
struct Node {
    int l,r;
}s[maxn+(maxn<<1)];
struct Seg {
    int l,r,s;
}t[maxn<<2];
int d[maxn<<2];
vector<int>g[maxn];
int n,m;
void build(int l,int r,int rt) {
    t[rt].l=l;
    t[rt].r=r;
    d[rt]=0;
    if (l==r) {
        t[rt].s=0;
        return ;
    }
    int mid = l+r>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    t[rt].s=t[rt<<1].s+t[rt<<1|1].s;
    return ;
}
void pd(int &rt) {

    if (d[rt]==0) {
        return ;
    }
    int len=t[rt].r-t[rt].l+1;
    t[rt<<1].s+=d[rt]*(len-(len>>1));
    t[rt<<1|1].s+=d[rt]*(len>>1);
    d[rt<<1]+=d[rt];
    d[rt<<1|1]+=d[rt];
    d[rt]=0;
    return ;
}
void update(int l,int r,int rt) {

    if (l<=t[rt].l&&t[rt].r<=r) {
        t[rt].s+=t[rt].r-t[rt].l+1;
        ++d[rt];
        return ;
    }
    pd(rt);
    int mid = t[rt].l+t[rt].r>>1;
    if (l<=mid) {
        update(l,r,rt<<1);
    }
    if (r>mid) {
        update(l,r,rt<<1|1);
    }
    return ;
}
int query(int rt,int where) {

    if (t[rt].l==t[rt].r) {
        return t[rt].s;
    }
    pd(rt);
    int mid = t[rt].l+t[rt].r>>1;
    if (where<=mid) {
        return query(rt<<1,where);
    }
    if (where>mid) {
        return query(rt<<1|1,where);
    }
}
int main() {

    scanf("%d%d",&n,&m);
    for (int i=0;i<=m;++i) {
        g[i].clear();
    }
    for (int i=1;i<=n;++i) {
        scanf("%d%d",&s[i].l,&s[i].r);
        int len=s[i].r-s[i].l+1;
        g[len].pb(i);
    }
    build(1,m,1);
    for(int i=1;i<=m;++i) {
        int ans=0;
        for (int j=0;j<g[i].size();++j) {
            int &pos=g[i][j];
            update(s[pos].l,s[pos].r,1);
        }
        for (int j=i;j<=m;j+=i) {
            ans+=query(1,j);
        }
        n-=g[i].size();
        printf("%d\n",ans+n);
    }
    return 0;
}
