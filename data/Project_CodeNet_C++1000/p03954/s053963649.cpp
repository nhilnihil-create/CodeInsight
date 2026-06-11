#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
int check(int x) 
{
	 for(register int i=0;i<n-1;i++) 
	 {
	 	if((a[n+i]>x&&a[n+i+1]>x)||(a[n-i]>x&&a[n-i-1]>x)) return 0;
	 	else if((a[n+i]<=x&&a[n+i+1]<=x)||(a[n-i]<=x&&a[n-i-1]<=x)) return 1;
	 }
	 return a[1]<=x;
}
int main() 
{
	scanf("%d",&n);
	for(register int i=1;i<=2*n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=0;
	int l=0,r=2*n-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			r=mid-1;
			ans=mid;
		}
		else 
		{
			l=mid+1;
		}
	}
	printf("%d",ans);
	return 0;
}
