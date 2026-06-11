#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(a[mid]<n-mid+1)l=mid+1;
		else r=mid-1;
	}
	int j=l-1;
	while(n-l+1==a[j])j--;
	j++;
	if(j!=l)
	{
		if(l-j&1)
		{
			printf("First\n");
			return 0;
		}
	}
	if(a[l]-(n-l+1)&1)printf("First\n");
	else printf("Second\n");
	return 0;
}