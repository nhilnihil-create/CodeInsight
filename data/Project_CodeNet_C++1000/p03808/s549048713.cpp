#include<bits/stdc++.h>
using namespace std;
#define re register
template <typename T> inline void read(T &x)
{
	x=0;int f=1;char c=getchar();
	for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T> inline void print(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+48);
}
long long a[100005],sum=0;
int main()
{
	int n;
	read(n);
	for(re int i=1;i<=n;++i)
	{
		read(a[i]);
		sum+=a[i];
	}
	long long all=1LL*n*(n+1)/2;
	if(sum%all!=0)
	{
		printf("NO");
		return 0;
	}
	long long k=sum/all;
	long long cnt=k;
	for(re int i=2;i<=n;++i)
	{
		if(a[i]-a[i-1]==k) continue;
		long long t=k-(a[i]-a[i-1]);
		if(t%n!=0||t<0)
		{
			printf("NO");
			return 0;
		}
		cnt-=t/n;
		if(cnt<0)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}