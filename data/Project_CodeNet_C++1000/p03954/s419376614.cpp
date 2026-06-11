#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n,l,r,mid;
int a[N],b[N];
inline void get(int &a)
{
	char c=getchar();
	a=0;
	for(;c<'0'||c>'9';c=getchar());
	a=c-'0';
	for(c=getchar();c>='0'&&c<='9';c=getchar())
		a=a*10+c-'0';
}
inline bool ok()
{
	for(int i=1;i<=2*n-1;i++)
		if(a[i]<=mid)
			b[i]=0;
		else
			b[i]=1;
	if(b[n]==0&&(b[n-1]==0||b[n+1]==0))
		return true;
	if(b[n]==1&&(b[n-1]==1||b[n+1]==1))
		return false;
	for(int i=n,j=n;i>1&&j<2*n-1;i--,j++)
	{
		if(b[i]==0&&b[i-1]==0)
			return true;
		if(b[i]==1&&b[i-1]==1)
			return false;
		if(b[j]==0&&b[j+1]==0)
			return true;
		if(b[j]==1&&b[j+1]==1)
			return false;
	}
	return !b[1];
}
int main()
{
	get(n);
	for(int i=1;i<=2*n-1;i++)
		get(a[i]);
	l=1,r=2*n-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(ok())
			r=mid-1;
		else
			l=mid+1;
	}
	printf("%d\n",r+1);
	return 0;
}