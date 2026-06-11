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
const int N=1010000;
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
int n,a[N];
bool check (int x)
{
	for (int i=0; i< n-1; i++)
	{
		if (a[n+i]> x&&a[n+i+1]> x) return 0;
		if (a[n-i]> x&&a[n-i-1]> x) return 0;
		if (a[n+i]<=x&&a[n+i+1]<=x) return 1;
		if (a[n-i]<=x&&a[n-i-1]<=x) return 1;
	}
	return a[1]<=x;
}
int main ()
{
	// freopen (".in","r",stdin);
	// freopen (".out","w",stdout);
	sc(n);
	for (int i=1; i< n*2; i++)
		sc(a[i]);
	int L=0,R=2*n;
	while (L+1< R)
	{
		int mid=(L+R)>>1;
		if (check (mid)) R=mid;
		else L=mid;
	}
	pr(R);

	return 0;
}
