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
inline void write(LL x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
inline void pr1(int x){write(x);putchar(' ');}
inline void pr2(LL x){write(x);putchar('\n');}
const int MAXN=2005;
const LL mod=1e9+7;
int n,K;
LL inv[MAXN*MAXN],pre[MAXN*MAXN];
LL pow_mod(LL a,LL b)
{
	LL ret=1;
	while(b)
	{
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ret;
}

LL f[MAXN][MAXN];
LL C(int n,int m){return pre[n]*inv[m]%mod*inv[n-m]%mod;}
void ad(LL &x,LL y){x+=y;if(x>=mod)x-=mod;}
int main()
{
	n=read();K=read();
	if(K==1)return puts("1"),0;
	pre[0]=1;for(int i=1;i<MAXN*MAXN;i++)pre[i]=pre[i-1]*i%mod;
	inv[MAXN*MAXN-1]=pow_mod(pre[MAXN*MAXN-1],mod-2);
	for(int i=MAXN*MAXN-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			if(i-1>=j)ad(f[i][j],f[i-1][j]);
			ad(f[i][j],f[i][j-1]*C(n*K-(K-1)*(j-1)-i-1,K-2)%mod);
		}
	f[n][n]=f[n][n]*pre[n]%mod;
	pr2(f[n][n]);
	return 0;
}
