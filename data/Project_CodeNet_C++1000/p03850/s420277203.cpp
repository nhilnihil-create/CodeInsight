#include<iostream>
#include<cstring>
#include<cstdio>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define MAXN 100010
using namespace std;
inline int read()
{
	int x=0,t=1,c;
	while(!isdigit(c=getchar()))if(c=='-')t=-1;
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*t;
}
int A[MAXN];
int op[MAXN];
long long normal[MAXN],rev[MAXN];
int main()
{
	int n=read();
	rep(i,1,n)
	{
		A[i]=read();
		if(i<n)
		{
			int c=getchar();
			while(c!='+'&&c!='-')c=getchar();
			if(c=='-')op[i+1]=-1;
			else op[i+1]=1;
		}
	}
	op[1]=1;
	normal[0]=0;
	rep(i,1,n)normal[i]=normal[i-1]+op[i]*A[i];
	long long sumv=0,ans=normal[n],block=0;
	dwn(i,n,1)
	{
		block+=A[i];
		if(op[i]==-1)
		{
			ans=max(ans,normal[i-1]-block+sumv);
			sumv+=block;
			block=0;
		}
	}
	printf("%lld",ans);
}