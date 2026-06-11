#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,a[MN+5];
long long ans=1e18,s[MN+5];
inline long long Abs(long long x){return x<0?-x:x;}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) s[i]=s[i-1]+(a[i]=read());
    for(int i=1;i<n;++i) ans=min(ans,Abs(s[i]-(s[n]-s[i])));
    cout<<ans;
    return 0;
}
