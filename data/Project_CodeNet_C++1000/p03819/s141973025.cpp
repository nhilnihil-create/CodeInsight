#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 300000
#define N 131072
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,m,Ans[MN+5],T[N*2+5];
vector<int> v[MN+5];
vector<pair<int,int> >q[MN+5];
inline void Renew(int x,int v){for(T[x+=N]+=v;x>>=1;)T[x]=T[x<<1]+T[x<<1|1];}
inline int Query(int l,int r)
{
    int res=0;
    for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
    {
        if(~l&1) res+=T[l+1];
        if( r&1) res+=T[r-1];
    }
    return res;
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i)
    {
        int l=read(),r=read();
        v[r].push_back(l);
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<m;j+=i)
        {
            int nx=min(m+1,j+i);
            if(j+1<=nx-1) q[nx-1].push_back(make_pair(j+1,i));
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<v[i].size();++j) Renew(v[i][j],1);
        for(int j=0;j<q[i].size();++j) Ans[q[i][j].second]+=Query(q[i][j].first,m);
    }
    for(int i=1;i<=m;++i) printf("%d\n",n-Ans[i]);
    return 0;
}
