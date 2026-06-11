#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=100005;
LL A[N],B[N],K;
int P[N],d[N],t[N],i,j,k,n,m,x;
char c;

inline char getc()
{
	#define VV 10000000
	static char s[VV],*l=s,*r=s;
	if (l==r)
		l=s,r=s+fread(s,1,VV,stdin);
	return l==r?0:*l++;
}

LL read(){ int k=1; LL z=0; do c=getc(); while ((c<'0'||c>'9')&&c!='-'); if (c=='-') k=-1,c=getc(); while (c>='0'&&c<='9') z*=10,z+=c-'0',c=getc(); return k*z; }

void power(int *P,LL K)
{
	for (i=1;i<=n;++i) d[i]=i;
	for (;K;K>>=1)
	{
		if (K&1)
		{
			for (i=1;i<n;++i) t[i]=P[d[i]];
			for (i=1;i<n;++i) d[i]=t[i];
		}
		for (i=1;i<n;++i) t[i]=P[P[i]];
		for (i=1;i<n;++i) P[i]=t[i];
	}
}

int main()
{
	n=read();
	for (i=1;i<=n;++i) B[i]=read(),A[i-1]=B[i]-B[i-1],P[i]=i;
	m=read(),K=read();
	for (i=1;i<=m;++i) x=read(),swap(P[x-1],P[x]);
	power(P,K);
	for (i=1;i<=n;++i) B[i]=B[i-1]+A[d[i-1]],printf("%lld.0\n",B[i]);
	return 0;
}