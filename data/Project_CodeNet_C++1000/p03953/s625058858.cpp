#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005;
int n,m,x[N],a[N],id[N],trf[N],trf1[N];
LL d[N],K;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

LL getLL()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void change(int id[],int trf[])
{
	rep(i,1,n-1) trf1[i]=trf[id[i]];
	rep(i,1,n-1) id[i]=trf1[i];
}

int main()
{
	n=getint();
	rep(i,1,n) x[i]=getint();
	rep(i,1,n-1) d[i]=x[i+1]-x[i],id[i]=trf[i]=i;
	m=getint(),K=getLL();
	rep(i,1,m)
	{
		int p=getint();
		swap(trf[p-1],trf[p]);
	}
	while(K)
	{
		if(K&1) change(id,trf);
		change(trf,trf),K>>=1;
	}
	LL p=x[1];
	rep(i,1,n)
	{
		printf("%lld\n",p);
		p+=d[id[i]];
	}
	return 0;
}