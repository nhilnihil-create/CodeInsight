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

const int inf=1e9+1e7,MAXN=1e2+1e1;

int a[MAXN];
int n,ans=0;

int main(void)
{

	// freopen("testdata.in","r",stdin);
	// freopen("testdata.out","w",stdout);

	scanf("%d",&n);

	for(int i=1;i<=n+n;i++) a[i]=readint;

	sort(a+1,a+n+n+1);

	for(int i=1;i<=n+n;i+=2) ans+=a[i];

	printf("%d\n",ans);

	return 0;

}