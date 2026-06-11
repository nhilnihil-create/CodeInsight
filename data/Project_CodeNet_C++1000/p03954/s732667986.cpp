#include<bits/stdc++.h>
using namespace std;
int a[2010101],b[2010101];
int br[2010101];
int n,ans,len;
bool check(int v)
{
	for (int i=1;i<=len;++i) 
	{
		if (a[i]>=v) b[i]=1;
		else b[i]=0;
	}
//	for (int i=1;i<=len;++i) printf("%d ",b[i]);
//	printf("\n");

	br[1]=-1;
	for (int i=2;i<=len;++i) 
	{
		if (b[i]==b[i-1]) br[i]=br[i-1]=b[i];
		else br[i]=-1;
	}
	
	if (br[n]!=-1) return br[n];

	int d[2];
	d[0]=d[1]=len;
	for (int i=1;i<=len;++i) if (br[i]!=-1) d[br[i]]=min(d[br[i]],abs(n-i));
	if (d[0]==len && d[1]==len)
	{
		int sss=b[n];
		if (n%2==0) sss=1-sss;
		return sss;
	}
	if (d[0]<d[1]) return 0;
	else return 1;
}
int main()
{
	scanf("%d",&n);
	len=2*n-1;
	for (int i=1;i<=len;++i) scanf("%d",&a[i]);

	int l=1,r=len;
	while (l<=r)
	{
		int mid=(l+r)/2;
//		printf("%d : %d\n",mid,check(mid));
		if (check(mid))
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}