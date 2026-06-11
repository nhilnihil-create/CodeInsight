#include<bits/stdc++.h>
using namespace std;
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
#define re register
const int mod=1e9+7;
int x[100005],n;
int mul(int a,int b)
{
	return 1LL*a*b%mod;
}
int main()
{
	read(n);
	for(re int i=1;i<=n;++i) read(x[i]);
	int pre=0,cnt=0,ans=1;
	for(re int i=1;i<=n;++i)
		if(x[i]>pre) cnt++,pre+=2;
		else ans=mul(ans,cnt+1);
	for(re int i=1;i<=cnt;++i) ans=mul(ans,i);
	printf("%d",ans);
	return 0;
}