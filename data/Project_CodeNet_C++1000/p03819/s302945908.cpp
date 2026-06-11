#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int maxn = 100000+5;
const LL mod = 1000000007;
struct Node {
    int l,r;
    int sum;
    int c;
}t[maxn<<2];
struct Seg {
    int l,r;
}s[maxn+(maxn<<1)];
vector<int>g[maxn];
void build(int l,int r,int rt) {
    t[rt].l=l;
    t[rt].r=r;
    t[rt].sum=0;
    t[rt].c=0;
    if (l==r) {
        return ;
    }
    int mid = (l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    return ;
}
void pushdown(int &rt) {
    if (!t[rt].c) {
        return ;
    }
    int len = t[rt].r-t[rt].l+1;
    t[rt<<1].sum+=t[rt].c*( len - (len>>1) );
    t[rt<<1|1].sum+=t[rt].c*( len>>1 );
    t[rt<<1].c+=t[rt].c;
    t[rt<<1|1].c+=t[rt].c;
    t[rt].c=0;
    return ;
}
void update(int l,int r,int rt,int val) {
    if (l<=t[rt].l&&t[rt].r<=r) {
        t[rt].sum+=val*(t[rt].r-t[rt].l+1);
        t[rt].c+=val;
        return ;
    }
    pushdown(rt);
    int mid = (t[rt].l+t[rt].r)>>1;
    if (l<=mid) {
        update(l,r,rt<<1,val);
    }
    if (r>mid) {
        update(l,r,rt<<1|1,val);
    }
    t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
    return ;
}
int query(int rt,int where) {
    if (t[rt].l==t[rt].r) {
        return t[rt].sum;
    }
    pushdown(rt);
    int mid = (t[rt].l+t[rt].r)>>1;
    if (where<=mid) {
        return query(rt<<1,where);
    }
    if (where>mid) {
        return query(rt<<1|1,where);
    }
}
int main() {
    
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,m,1);
    for (int i=1;i<=n;++i) {
        scanf("%d%d",&s[i].l,&s[i].r);
        int len = s[i].r-s[i].l+1;
        g[len].push_back(i);
    }
    for (int i=1;i<=m;++i) {
        int ans=0;
        n-=g[i-1].size();
        for (int j=0;j<g[i-1].size();++j) {
            int &pos=g[i-1][j];
            update(s[pos].l,s[pos].r,1,1);
        }
        for (int j=i;j<=m;j+=i) {
            ans+=query(1,j);
        }
        printf("%d\n",ans+n);
    }
    return 0;
}