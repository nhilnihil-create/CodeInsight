#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,b,a) for(int i=b;i>=a;--i)
#define efo(i,v,u) for(int i=BB[v],u=B[BB[v]][1];i;i=B[i][0],u=B[i][1])
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define cmax(x,y) ((x)<(y)?(x)=(y):(x))
#define cmin(x,y) ((x)>(y)?(x)=(y):(x))
#define mset(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
char ch;
int read(){int n=0,p=1;for(ch=getchar();ch<'0' || ch>'9';ch=getchar())if(ch=='-') p=-1;for(;'0'<=ch && ch<='9';ch=getchar()) n=n*10+ch-'0';return n*p;}
const int N=1e5+5;
int n,a[N];
int gcd(int x,int y)
{
	if(x%y==0) return y;
	return gcd(y,x%y);
}
bool work()
{
	int cnteven=0,cntodd=0,ps=0;
	fo(i,1,n)
		if(a[i]&1) ++cntodd,ps=i;else ++cnteven;
	if(cnteven&1) return 0;
	if(cntodd==1 && a[ps]>1)
	{
		a[ps]--;
		int t=a[1];
		fo(i,1,n) t=gcd(t,a[i]);
		fo(i,1,n) a[i]/=t;
		return work()^1;
	}
	else return 1;
}
int main()
{
	n=read();
	fo(i,1,n) a[i]=read();
	puts(work()?"Second":"First");
	return 0;
}