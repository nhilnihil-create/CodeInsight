//Love and Freedom.
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#define ll long long
#define inf 20021225
#define N 100010
using namespace std;
int read()
{
	int s=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return f*s;
}
int a[N<<1],tmp[N<<1],n;
bool check(int x)
{
	for(int i=1;i<(n<<1);i++)	tmp[i]=a[i]>=x;
	int mid=n;
	for(int d=0;d<n-1;d++)
	{
		if(tmp[mid-d-1]==tmp[mid-d])	return tmp[mid-d];
		if(tmp[mid+d+1]==tmp[mid+d])	return tmp[mid+d];
	}
	return tmp[1];
}
int main()
{
	n=read(); int mx=1;
	for(int i=1;i<(n<<1);i++)	a[i]=read(),mx=max(mx,a[i]);
	int l=1,r=mx,ans=1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))	l=mid+1,ans=mid;
		else	r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}