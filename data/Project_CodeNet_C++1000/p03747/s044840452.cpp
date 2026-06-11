#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=100005;
LL s;
int A[N],i,j,k,n,m,l,T,x;
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

int main()
{
	n=read(),l=read(),T=read();
	for (i=0;i<n;++i)
	{
		x=read(),
		x+=read()==1?T:-T,
		s+=x/l,x%=l;
		if (x<0) x+=l,--s;
		A[i]=x;
	}
	sort(A,A+n);
	s=(s%n+n)%n;
	for (i=0;i<n;++i) printf("%d\n",A[(i+s)%n]);
	return 0;
}