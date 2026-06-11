#include <algorithm>
// #include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
// #include <bitset>
const int oo=2139063143;
const int N=2010;
const int P=1000000007;
using namespace std;
typedef long long LL;
typedef double db;
#define pritnf printf
//char buf[1<<22],*p1=buf,*p2=buf,obuf[1<<22],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void sc (T &x)
{
    x=0; static int p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
}
template <typename T>
inline void print (T x)
{
	if (x< 0) putchar('-'),x=-x;
	if (x>=10) print(x/10);
	putchar(x%10+'0');
}
template <typename T>
inline void pr (T x) { print(x),putchar('\n'); }
int del(int x) { return x>=P?x-P:x; }
void add(int &x,int y) { x=del(x+y); }
int ksm (int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=(LL)ans*a%P;
		a=(LL)a*a%P,b>>=1;
	}
	return ans;
}
int jc[N*N],inv[N*N];
void init (int n)
{
	jc[0]=1;
	for (int i=1; i<=n; i++)
		jc[i]=(LL)i*jc[i-1]%P;
	inv[n]=ksm (jc[n],P-2);
	for (int i=n-1; i>=0; i--)
		inv[i]=(LL)(i+1)*inv[i+1]%P;
}
int C(int n,int m) { return n< m?0:(LL)jc[n]*inv[m]%P*inv[n-m]%P; }
int f[N][N];
int main ()
{
	// freopen (".in","r",stdin);
	// freopen (".out","w",stdout);
	int n,k; sc(n),sc(k);
	if (k==1||n==1) return pr(1),0;
	init (n*k);
	f[0][0]=1;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=i; j++)
		{
			f[i][j]=f[i-1][j];
			if (j) add(f[i][j],(LL)f[i][j-1]*(n-j+1)%P*C(n*k-i-(k-1)*(j-1)-1,k-2)%P);
		}
	pr(f[n][n]);

	return 0;
}