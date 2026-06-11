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
const int MAXN=1000005;
const int mod=1e9+7;
int f[MAXN],g[2*MAXN],n;
void ad(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void dl(int &x,int y){x-=y;if(x<0)x+=mod;}
int main()
{
	n=read();f[0]=1;int sum=0;
	for(int i=0;i<=n;i++)
	{
		ad(sum,g[i]);
		ad(f[i],sum);
		if(i<n)
		{
			ad(g[i+1],f[i]);
			dl(g[i+2],f[i]);ad(g[i+3],f[i]);
			dl(g[i+(n+1)+1],f[i]);
		}
	}
	int ans=0;
	for(int i=n+1;i<=2*n;i++)
	{
		ad(sum,g[i]);
		ad(ans,sum);
	}
	for(int i=0;i<n-1;i++)ad(ans,1LL*f[i]*(n-1)%mod*(n-1)%mod);
//	ad(ans,1LL*f[n-1]*(n-1)%mod);
	ad(ans,f[n]);
	pr2(ans);
	return 0;
}

