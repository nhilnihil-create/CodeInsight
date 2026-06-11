#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define F(x) for(int i=1;i<=(x);i++)
#define fer(i,n) for(int i=1;i<=(n);i++)
#define FIN  {freopen("1.in","r",stdin);}
#define FOUT {freopen("1.out","w",stdout);}
#define OUT(x)  {cout<<"#x"<<" : "<<x<<endl;}
#define ERR(x)  {cout<<"#error:"<<x;while(1);}
typedef long long ll;
typedef unsigned long long ull;
#define se second
#define fi first
#define make_pair mkp
#define mid ((l+r)>>1)
const int MaxInt = -1u>>1;
const int Max_ = 0x3f3f3f;
const double eps = 1e-6;
const double pi = acos(-1);
using namespace std;
inline int read()
{
    char ch=getchar();int f=1,g=0;
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) g=g*10+(ch^48);
    return g*f;
}
const int N = 2005;
int n,k;
int head[N*2],nt[N*2],to[N*2],cnt=0,num=0,ans=0;
inline void add(int u,int v)
{
    nt[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}
void dfs(int x,int f,int now)
{
    num++;if(now==0)return;
    for(int y,i=head[x];i;i=nt[i])
        if((y=to[i])!=f)
            dfs(y,x,now-1);
}
int main()
{
    n=read(),k=read();
    F(n-1) {int a=read(),b=read();add(a,b),add(b,a);}
    if(!(k&1))
    {
        F(n) {
            num=0;dfs(i,0,k/2);ans=max(num,ans);
        }
    }
    else
    {
        F(n) for(int j=head[i];j;j=nt[j]) {
            num=0;int y=to[j];
            dfs(y,i,k/2);
            dfs(i,y,k/2);
            ans=max(num,ans);
        }
    }
    cout<<n-ans<<endl;
    return 0;
}