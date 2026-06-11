#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
inline int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
const int MAXN=100005;
struct edge{int x,y,next;}a[4*MAXN];int len,last[MAXN];
void ins(int x,int y){len++;a[len].x=x;a[len].y=y;a[len].next=last[x];last[x]=len;}
int vis[MAXN],rt[MAXN],ok[MAXN],tot[MAXN],num,n,m;
bool OK;
void dfs(int x,int col)
{
	vis[x]=col;bool ret=true;++num;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;if(vis[y]==-1)dfs(y,col^1);
		else if(vis[y]!=vis[x]^1)OK=false;
	}
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		ins(x,y);ins(y,x);
	}memset(vis,-1,sizeof(vis));
	int siz=0,siz1=0;
	for(int i=1;i<=n;i++)if(vis[i]==-1)
	{
		rt[i]=1;num=0;++siz;OK=1;
		if(!last[i])ok[i]=2,++siz1;
		else dfs(i,0),ok[i]=OK;tot[i]=num;
	}int cnt=0;LL ans=0;
	for(int i=1;i<=n;i++)if(rt[i]&&ok[i]==1)++cnt;
	for(int i=1;i<=n;i++)if(rt[i])
	{
		if(ok[i]==2)ans+=n;
		else if(!ok[i])ans+=siz-siz1,ans+=1LL*siz1*tot[i];
		else
		{
			ans+=cnt*2;
			ans+=siz-siz1-cnt;
			ans+=1LL*siz1*tot[i];
		}
	}pr2(ans);
	return 0;
}
