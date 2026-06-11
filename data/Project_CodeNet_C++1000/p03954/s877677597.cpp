#include<algorithm>
#include<cstdio>
#define M 2400042
#define N 200001
using namespace std;
char G[M],*g=G;
inline int read()
{
	int x=0;bool w=false;
	while(*g<48||57<*g)if(*g++=='-')w=true;
	while(47<*g&&*g<58)x=(x<<1)+(x<<3)+(*g++^48);
	return w?-x:x;
}
int a[N],b[N],i,l,m,n,r;
inline bool check(int o)
{
	for(i=1;i<n;i++)
	if((a[n-i]>o)==(a[n-i+1]>o))return a[n-i]>o;
	else if((a[n+i]>o)==(a[n+i-1]>o))return a[n+i]>o;
	return n&1?a[n]>o:a[n]<=o;
}
int main()
{
	fread(G,1,M,stdin),n=read(),m=n<<1;
	for(i=1;i<m;i++)a[i]=b[i]=read();
	sort(b+1,b+m),l=1,r=m-1;
	while(l<r)check(b[l+r>>1])?l=l+r+2>>1:r=l+r>>1;
	printf("%d\n",b[l]); 
	return 0;
}