// copied
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int maxn=2e5+1e2;
#define LL long long

int a[maxn];

int getint()
{
	char ch;int b=1;
	for(ch=getchar();ch>'9'||ch<'0';ch=getchar())if(ch=='-')b=-1;
	int num=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar())num=num*10+ch-'0';
	return num*b;
}

int main()
{
	int n=getint();
	LL sum=0;
	for(int i=1;i<=n;i++){a[i]=getint();sum+=a[i];}
	LL re=0,ans=1e17;
	for(int i=1;i<n;i++)
	{
		re+=a[i];
		ans=min(ans,abs(sum-re-re));
	}
	printf("%lld\n",ans);
	return 0;
}
