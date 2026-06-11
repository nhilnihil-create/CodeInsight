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
struct edge{int x,y,next;}a[2*MAXN];int len,last[MAXN];
void ins(int x,int y){len++;a[len].x=x;a[len].y=y;a[len].next=last[x];last[x]=len;}
int root,du[MAXN],n,num[MAXN],up[MAXN];
int tot[MAXN],ln;
void gg(){puts("NO");exit(0);}
void solve(int x,int fa)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)solve(y,x);
	}if(du[x]==1){up[x]=num[x];return ;}
	ln=0;LL sum=0;int mx=0;
	for(int k=last[x];k;k=a[k].next)if(a[k].y!=fa)tot[++ln]=up[a[k].y];
	for(int i=1;i<=ln;i++)sum+=tot[i],mx=max(mx,tot[i]);
	if(sum<num[x])gg();
	if(x!=root)
	{
		LL lim=0;
		if(mx>sum-mx)lim=sum-mx;else lim=sum/2;
		if(sum-lim>num[x])gg();
		up[x]=sum-2*(sum-num[x]);
	}
	else
	{
		LL lim=0;
		if(mx>sum-mx)lim=sum-mx;else lim=sum/2;
		if(lim*2!=sum)gg();if(lim!=num[x])gg();
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)num[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ins(x,y);ins(y,x);++du[x];++du[y];
	}
	if(n==2)return puts(num[1]==num[2]?"YES":"NO"),0;
	for(int i=1;i<=n;i++)if(du[i]>=2){root=i;break;}
	solve(root,0);
	puts("YES");
	return 0;
}
