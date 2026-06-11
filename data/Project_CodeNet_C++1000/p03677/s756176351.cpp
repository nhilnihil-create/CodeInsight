#include<algorithm>
#include<iostream>
#include<cstdlib>
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
int n,m;
long long ans=1e18,s[MN+5],a[MN+5],b[MN+5];
inline void Add(long long*s,int l,int r,int v){s[l]+=v;s[r+1]-=v;}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) b[i]=read();
    for(int i=2;i<=n;++i)
    {
        if(b[i]>b[i-1])
            Add(s,1,b[i-1],b[i]-b[i-1]),
            Add(s,b[i]+1,m,b[i]-b[i-1]),
            Add(a,b[i-1]+1,b[i],-1),
            Add(s,b[i-1]+1,b[i],b[i]+1);
        else Add(s,b[i]+1,b[i-1],m-b[i-1]+b[i]),
             Add(a,b[i-1]+1,m,-1),
             Add(s,b[i-1]+1,m,m+b[i]+1),
             Add(a,1,b[i],-1),
             Add(s,1,b[i],b[i]+1);
    }
    for(int i=1;i<=m;++i) s[i]+=s[i-1],a[i]+=a[i-1],ans=min(ans,a[i]*i+s[i]);//cout<<i<<" "<<a[i]*i+s[i]<<endl;
    cout<<ans;
    return 0;
}
