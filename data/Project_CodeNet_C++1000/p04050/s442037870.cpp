#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,a[MN+5],mx,Ans[MN+5],ans,c[5],num;
inline void Add(int x){if(x)Ans[++ans]=x;}
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;++i) a[i]=read(),mx+=a[i]>>1;
    if(mx+(n>>1)<n-1) return 0*puts("Impossible");
    if(m==1) Add(1),Add(a[1]-1);
    else if(m==2) Add(a[1]-1),Add(a[2]+1);
    else
    {
        for(int i=1;i<=m;++i) if(a[i]&1)
        {
            if(a[1]&1) swap(a[i],a[m]);
            else swap(a[i],a[1]);
        }
        Add(a[1]-1);
        for(int i=2;i<m;++i) Add(a[i]);
        Add(a[m]+1);
    }
    for(int i=1;i<=m;++i) printf("%d%c",a[i],i==m?'\n':' ');
    printf("%d\n",ans);
    for(int i=1;i<=ans;++i) printf("%d ",Ans[i]);
    return 0;
}
