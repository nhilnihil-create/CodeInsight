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
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
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
LL a[MAXN],n,m,b[MAXN];LL K;
LL p[MAXN],ans[MAXN],vis[MAXN];
LL ri[MAXN],tot;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i>=1;i--)a[i]=a[i]-a[i-1];
	m=read();K=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=m;i++)swap(p[b[i]],p[b[i]+1]);
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		tot=0;ri[++tot]=i;vis[i]=1;
		for(int j=p[i];j!=i;j=p[j])ri[++tot]=j,vis[j]=1;
		for(int j=1;j<=tot;j++)ans[ri[j]]=a[ri[(j+K%tot-1)%tot+1]];
	}
	for(int i=1;i<=n;i++)pr2(ans[i]+=ans[i-1]);
	return 0;
}
