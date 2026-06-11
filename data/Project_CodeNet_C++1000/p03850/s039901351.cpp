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
#include<assert.h>
#include<chrono>
#include<random>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
template<typename T>inline void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T>inline void chkmax(T &x,T y){x=x>y?x:y;}
const int MAXN=100005;
int a[MAXN],n,opt[MAXN];char ch[15];
LL gi(int x)
{
	if(opt[x]!=1)return a[x];
	return a[x]+gi(x+1);
}
int main()
{
//	freopen("a.txt","r",stdin);
	n=read();LL sum=0;
	int fi=-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();sum+=a[i];
		if(i!=n)
		{
			scanf("%s",ch+1);
			opt[i]=ch[1]=='+'?1:-1;
			if(opt[i]==-1&&fi==-1)fi=i;
		}
	}
	if(fi==-1)return pr2(sum),0;
	if(opt[fi+1]==-1)return pr2(sum-2*a[fi+1]),0;
	LL ans=-1e18;chkmax(ans,sum-2*a[fi+1]-2*gi(fi+2));sum-=2*a[fi+1];
	for(int i=fi+1;i<n;i++)
	{
		if(opt[i]==-1)
		{
			if(opt[i+1]==-1)chkmax(ans,sum-2*a[i+1]);
			else chkmax(ans,sum-2*a[i+1]-2*gi(i+2));
			sum-=2*a[i+1];
		}
	}pr2(ans);
	return 0;
}

