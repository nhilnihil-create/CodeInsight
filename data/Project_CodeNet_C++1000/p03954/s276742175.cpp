#include<cstdio>
#include<cmath>
#define neko 200010
#define f(i,a,b) for(register int i=(a);i<=(b);i=-(~i))
using std::abs;
int n,m,a[neko],Mid;
int cmin(int x,int y){return x<y?x:y;}
bool check(int x)
{
	for(register int i=Mid,j=Mid;i&&j<=m;--i,++j)
	{
	//	printf("%d %d %d\n",x,i,j);
		if((a[i]<x)&&(a[i-1]<x))return 0;
		if((a[i]>=x)&&(a[i-1]>=x))return 1;
		if((a[j]<x)&&(a[j+1]<x))return 0;
		if((a[j]>=x)&&(a[j+1]>=x))return 1;
	}
	return a[1]>=x;
}
int main()
{
	scanf("%d",&n),Mid=(m=2*n-1)+1>>1;
	f(i,1,m)scanf("%d",&a[i]);
	int l=1,r=m,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}return printf("%d\n",ans),0;
}