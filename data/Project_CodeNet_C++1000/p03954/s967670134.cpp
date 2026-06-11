#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[200010],b[200010];
bool check(int k)
{
	for(int i=1;i<=2*n-1;i++) b[i]=(a[i]>=k);
	if (b[n]==b[n+1]||b[n-1]==b[n]) return b[n];
    for (int l=n,r=n;l>=1;l--,r++)
    {
        if(b[l]==b[l+1]) return b[l];
        if(b[r]==b[r-1]) return b[r];
    }
    return b[n]^(n&1)^1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++) scanf("%d",&a[i]);
	int l=1,r=2*n-1,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}