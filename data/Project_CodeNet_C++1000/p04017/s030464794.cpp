#include<bits/stdc++.h>
#define ll long long
#define swap(x,y) {x^=y,y^=x,x^=y;}
using namespace std;
const int maxn=2e5+10;
int N,L,f[maxn][35],t,Q,x[maxn];
inline long long read()
{
    long long s=0,f=1; char ch; for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+ch-'0'; return s*f;
}
void Work_preparing()
{
    for(int i=1;i<=N;++i)
    {
        f[i][0]=upper_bound(x+1,x+N+1,1LL*(x[i]+L))-x-1;
        //printf("He can reach %d ,from %d in a day.\n",x[pos],x[i]);
    }
    for(int j=1;j<=t;++j)
    {
        for(int i=1;i<=N;++i)
        f[i][j]=f[f[i][j-1]][j-1];
    }
}
ll solve(int l,int r)
{
    ll ans=0;
    for(int i=t;i>=0;--i)
    {
        if(f[l][i]<r) ans+=(1<<i),l=f[l][i];
    }
    return ans+1;
}
void Input()
{
    N=read(); t=(int)(log(N)/log(2));
    for(int i=1;i<=N;++i) x[i]=read();
    L=read(); Work_preparing(); Q=read();
    while(Q--)
    {
        int a,b; a=read(),b=read();
        if(a>b)          swap(a,b);
        printf("%lld\n", solve(a,b));
    }
}
int main()
{
    Input(); return 0;
}
