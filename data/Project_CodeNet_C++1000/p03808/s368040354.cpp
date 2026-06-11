#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100005;
int n,i,a[N];
ll sum,w,c[N];
int main()
{
	//freopen("boxes.in","r",stdin);
	//freopen("boxes.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		sum+=a[i];
	}
	if(sum%(1ll*(1+n)*n/2))
	{
		printf("NO");
		return 0;
	}
	sum/=1ll*(1+n)*n/2;
	w=a[1]-a[n];
	for(i=2;i<=n;++i)
		w+=a[i]-a[i-1];
	if(w!=0)
	{
		printf("NO");
		return 0;
	}
	c[1]=a[1]-a[n];
	for(i=2;i<=n;++i)
		c[i]=a[i]-a[i-1];
	for(i=1;i<=n;++i)
		c[i]-=sum;
	for(i=1;i<=n;++i)
		if(c[i]>0||c[i]%n)
		{
			printf("NO");
			return 0;
		}
	for(i=1;i<=n;++i)
		sum+=c[i]/n;
	if(sum==0)
		printf("YES");
	else
		printf("NO");
	return 0;
}
