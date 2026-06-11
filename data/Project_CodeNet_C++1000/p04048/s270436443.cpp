#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<ctime>

using namespace std;

template <typename T>

inline T read()
{
	T x=0,f=1;char c=getchar();
	while(!isdigit(c))
	{if(c=='-') f=-f;c=getchar();}
	while(isdigit(c))
	{x=(x<<3)+(x<<1)+(c-48);c=getchar();}
	return x*f;
}

#define lint long long int
#define ulint unsigned lint
#define readint read<int>()
#define readlint read<lint>()

const int inf=1e9+1e7;

lint ans=0,x,n;

lint Eclid(lint N,lint X)
{
	if(!(N%X)) return (N/X)*X*2-X;
	else return Eclid(X,N%X)+(N/X)*X*2;
}

int main(void)
{
	// freopen("testdata.in","r",stdin);
	// freopen("testdata.out","w",stdout);
	scanf("%lld%lld",&n,&x);
	ans=n+Eclid(x,n-x);
	printf("%lld\n",ans);
	return 0;
}