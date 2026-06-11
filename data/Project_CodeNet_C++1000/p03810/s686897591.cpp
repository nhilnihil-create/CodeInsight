#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=100005;
LL S;
int z[N],A[N],i,j,k,n,m,d,G;
bool F;
char c;

inline char getc()
{
	#define VV 10000000
	static char s[VV],*l=s,*r=s;
	if (l==r)
		l=s,r=s+fread(s,1,VV,stdin);
	return l==r?0:*l++;
}

int read(){ int z=0; do c=getc(); while (c<'0'||c>'9'); while (c>='0'&&c<='9') z*=10,z+=c-'0',c=getc(); return z; }

bool check(int G)
{
	return S/G&1;
}

void make()
{
	G=1;
	if (!check(G=__gcd(A[1]-1,z[2])))
	{
		d=A[1];
		for (register int i=2;i<n;d=__gcd(d,A[i]),++i)
			if (check(G=__gcd(__gcd(d,A[i]-1),z[i+1])))
			{
				--A[i];
				return;
			}
		if (check(G=__gcd(d,A[n]-1)))
			--A[n];
	}
	else
		--A[1];
}

bool solve()
{
	n=read(),S=-1;
	if (n==1) return 0;
	for (register int i=1;i<=n;++i) A[i]=read(),F^=A[i]&1,S+=A[i];
	if (!(n&1)) return F;
	if (!F) return 1;
	while (1)
	{
		z[n]=A[n];
		bool P=0;
		for (register int i=n-1;i;--i) z[i]=__gcd(z[i+1],A[i]),P|=A[i]==1;
		if (P) return !F;
		make();
		if (!check(G)) return !F;
		S=-1;
		for (register int i=1;i<=n;++i)
			A[i]/=G,S+=A[i];
		F^=1;
	}
}

int main()
{
	puts(solve()?"First":"Second");
	return 0;
}