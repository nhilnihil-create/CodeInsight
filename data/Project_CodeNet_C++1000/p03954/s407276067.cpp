#include<bits/stdc++.h>
using namespace std;
int n,a[2000005];
inline bool check(int k)
{
    for(int i=0;i<n-1;i++)
	{
        if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))
			return true;
        if((a[n+i]>k&&a[n+i+1]>k)||(a[n-i]>k&&a[n-i-1]>k))
			return false;
    }
    if(a[1]<=k)
    	return true;
    else
    	return false;
}
int main()
{
	scanf("%d",&n);
    for(int i=1;i<n*2;i++)
		scanf("%d",&a[i]);
    int l=1,r=n*2-1;
    while(l<r)
	{
        int mid=(l+r)/2;
        if(check(mid))
			r=mid;
        else 
			l=mid+1;
    }
    printf("%d\n",l);
}