#include<cstdio>
using namespace std;
#define N 233333
int a[N],b[N],n;
bool check(int s)
{
	for(int i=1;i<2*n;i++)b[i]=(a[i]>=s);
	for(int i=n;i>1;i--)
	{
		if(b[i]==b[i-1])return b[i];
		if(b[n*2-i]==b[n*2-i+1])return b[n*2-i];
	}
	return b[1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n*2;i++)
	scanf("%d",&a[i]);
	int lb=0,rb=233333,ans=0;
	while(lb<=rb)
	{
		int mid=(lb+rb)>>1;
		if(check(mid))ans=mid,lb=mid+1;
		else rb=mid-1;
	}
	printf("%d\n",ans);
}