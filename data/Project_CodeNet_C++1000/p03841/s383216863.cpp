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
const int MAXN=505;
int a[MAXN*MAXN],n,ps[MAXN],id[MAXN];
bool cmp(int n1,int n2){return ps[n1]<ps[n2];}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)ps[i]=read(),id[i]=i;
	sort(id+1,id+1+n,cmp);
	for(int i=1,len=1;i<=n;i++)
	{
		int u=id[i];
		while(a[len])++len;if(len>ps[u])return puts("No"),0;
		a[ps[u]]=u;int cnt=0;
		while(cnt<u-1)
		{
			while(a[len])++len;
			if(len>=ps[u])return puts("No"),0;
			a[len]=u;++cnt;
		}
	}int len=n*n;
	for(int i=n;i>=1;i--)
	{
		int cnt=0;int u=id[i];
		while(cnt<n-u)
		{
			while(a[len])--len;
			if(len<=ps[u])return puts("No"),0;
			a[len]=u;++cnt;
		}
	}puts("Yes");
	for(int i=1;i<=n*n;i++)pr1(a[i]);puts("");
	return 0;
}
