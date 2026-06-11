#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int A[N],i,j,k,n,m;
bool an;
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
	n=read();
	for (i=1;i<=n;++i) A[i]=read();
	sort(A+1,A+n+1),reverse(A+1,A+n+1);
	for (i=1;i<=n;++i)
		if (i+1>A[i+1])
		{
			for (j=i+1;i==A[j];++j)
				an^=1;
			an|=A[i]-i&1;
			puts(an?"First":"Second");
			return 0;
		}
}