#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100005];
int dp[100005][50];

ll read()
{
	ll sum=0;int f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}

int main()
{
    int n=read();
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=read(),q=read();
    for(int i=1;i<=n;i++)
    {
        int id=upper_bound(a+1,a+1+n,a[i]+l)-a-1;
        if(a[i]+l>=a[n])
            dp[i][0]=n;
        else
            dp[i][0]=id;
    }
     
    for(int i=1;i<=30;i++)
    {
        for(int j=1;j<=n;j++)
            dp[j][i]=dp[dp[j][i-1]][i-1];
    }
    while(q--)
    {
        int s=read(),e=read();
        if(e<s)
            swap(s,e);  
        long long ans=0;
        for(int i=30;i>=0;i--)
        {
            if(dp[s][i]<e)
            {
                ans=ans+(1ll<<i);
                s=dp[s][i];
            }
        }
        printf("%lld\n",ans+1);
    }
    return 0;
}