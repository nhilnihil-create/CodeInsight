#include<bits/stdc++.h>
using namespace std;
int L,Q,n,a[100005],dp[100005][30];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d%d",&L,&Q);
    for(int i=1;i<=n;i++)
    {
    	int id=upper_bound(a+1,a+1+n,a[i]+L)-a-1;
    	if(a[i]+L>=a[n])
            dp[i][0]=n;
        else
            dp[i][0]=id;
	}
	for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            dp[j][i]=dp[dp[j][i-1]][i-1];
    while(Q--)
    {
    	int L,R;
    	scanf("%d%d",&L,&R);
    	if(R<L)
    		swap(L,R);
    	long long ans=0;
    	for(int i=20;i>=0;i--)
    		if(dp[L][i]<R)
    		{
    			ans+=(1ll<<i);
    			L=dp[L][i];
			}
		printf("%lld\n",ans+1);
	}
	return 0;
}