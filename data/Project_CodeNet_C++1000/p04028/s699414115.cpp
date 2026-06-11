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
const int MAXN=5005;
const int mod=1e9+7;
void ad(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int f[MAXN][MAXN],g[MAXN][MAXN],n;char ch[MAXN];
int main()
{
	n=read();scanf("%s",ch+1);int len=strlen(ch+1);
	f[n][len]=1;int ans=0;
	for(int i=n;i>=1;i--)for(int j=1;j<=n;j++)if(f[i][j])
	{
		if(j!=0)ad(f[i-1][j+1],2LL*f[i][j]%mod);//backspace
		ad(f[i-1][j-1],f[i][j]);
	}
	g[0][0]=1;
	for(int i=0;i<n;i++)for(int j=0;j<=i;j++)if(g[i][j])
	{
		ad(g[i+1][max(j-1,0)],g[i][j]);
		ad(g[i+1][j+1],2LL*g[i][j]%mod);
	}
	for(int i=0;i<=n;i++)if(f[i][0])
		ad(ans,1LL*g[i][0]*f[i][0]%mod);
	pr2(ans);
	return 0;
}

