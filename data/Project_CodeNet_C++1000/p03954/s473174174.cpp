#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define reg register
using namespace std;
const int N=2e5+5;
int n,a[N];
inline int read()
{
	int x=0,w=1;
	char c=getchar();
	while (!isdigit(c)&&c!='-') c=getchar();
	if (c=='-') c=getchar(),w=-1;
	while (isdigit(c))
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*w;
}
inline bool check(int k)
{
	for (reg int i=1;i<n;i++)
	{
		if ((a[n-i+1]>k)==(a[n-i]>k)) return a[n-i]<=k;
		if ((a[n+i-1]>k)==(a[n+i]>k)) return a[n+i]<=k;
	}
	return a[1]<=k;
}
int main()
{
	n=read();
	for (reg int i=1;i<(n<<1);a[i++]=read());
	int l=1,r=(n<<1)-1,ans=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}