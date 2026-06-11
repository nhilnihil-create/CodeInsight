#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define maxn 300010
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
struct P{
    int l,r;
}a[maxn];
vector<int>v[maxn];
int rt[maxn];
struct Segment_Tree{
    int t[maxn*20],ls[maxn*20],rs[maxn*20],tot;
    void update(int k)
    {
        t[k]=t[ls[k]]+t[rs[k]];
    }
    void modi(int &k1,int k2,int l,int r,int x)
    {
        k1=++tot;
        if(l==r)
        {
            t[k1]=t[k2]+1;
            return;
        }
        int mid=(l+r)/2;
        if(mid>=x)  rs[k1]=rs[k2],modi(ls[k1],ls[k2],l,mid,x);
        else        ls[k1]=ls[k2],modi(rs[k1],rs[k2],mid+1,r,x);
        update(k1);
    }
    int query(int k1,int k2,int l,int r,int x,int y)
    {
        if(l>=x&&r<=y)  return t[k1]-t[k2];
        int mid=(l+r)/2;
        int res=0;
        if(mid>=x)  res+=query(ls[k1],ls[k2],l,mid,x,y);
        if(mid<y)   res+=query(rs[k1],rs[k2],mid+1,r,x,y);
        return res;  
    }
}S;
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)  a[i].l=read(),a[i].r=read(); 
    for(int i=1;i<=n;i++)  v[a[i].l].push_back(a[i].r);
    for(int i=1;i<=m;i++)
    {
        if(!v[i].size())
        {
            rt[i]=rt[i-1];
            continue;
        }
        int las=rt[i-1];
        for(int j=0;j<v[i].size();j++)
        {
            S.modi(rt[i],las,1,m,v[i][j]);
            las=rt[i];
        }
    }
    for(int i=1;i<=m;i++)
    {
        int ans=0;
        for(int j=i;j<=m;j+=i)  ans+=S.query(rt[j],rt[j-i],1,m,j,m);
        printf("%d\n",ans);
    }
    return 0;
}