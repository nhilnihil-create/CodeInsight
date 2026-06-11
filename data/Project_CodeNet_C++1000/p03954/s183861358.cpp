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
const int MAXN=200005;
int a[MAXN],b[MAXN],s[MAXN],n;
struct line
{
	int l,r;
	line(){}
	line(int _l,int _r){l=_l;r=_r;}
}sta[MAXN];int tp;
bool check(int u)
{
	for(int i=1;i<=2*n-1;i++)b[i]=(a[i]>=u?1:0);b[0]=b[1];
	for(int i=2*n-1;i>=1;i--)b[i]^=b[i-1];tp=0;
	memset(s,0,sizeof(s));
	for(int i=1,nxt;i<=2*n-1;i=nxt+1)
	{
		if(!b[i]){nxt=i;continue;}
		nxt=i;while(nxt+1<=2*n-1&&b[nxt+1])++nxt;
		if(nxt-i+1>=2)sta[++tp]=line(i,nxt);
		else s[i]^=1;
	}
	for(int i=1;i<n;i++)
	{
		int tp1=0;
		for(int j=1;j<=tp;j++)
		{
			int u1=sta[j].l,u2=sta[j].r;
			++u1;--u2;
			if(u2-u1+1>=2)sta[++tp1]=line(u1,u2);
			else if(u2-u1+1)s[u2]^=1;
		}tp=tp1;
	}int o=b[0],mi=n;
	for(int i=1;i<=mi;i++)o^=s[i];
	for(int i=1;i<=tp;i++)
	{
		if(sta[i].r<n)o^=((sta[i].r-sta[i].l+1)&1);
		else if(sta[i].l>n)break;
		else {o^=((mi-sta[i].l+1)&1);break;}
	}return o;
}
int main()
{
	n=read();
	for(int i=1;i<=2*n-1;i++)a[i]=read();
	int l=1,r=2*n-1,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}pr2(ans);
	return 0;
}
