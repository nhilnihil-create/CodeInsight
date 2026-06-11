#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[2005],b[2005][2005],n,x,ans=9e18;
int main()
{
    scanf("%lld%lld",&n,&x);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        b[i][i]=a[i];
        for(int j=i+1;j<=n;j++)
        {
            b[i][j]=min(b[i][j-1],a[j]);
        }
    }
    for(ll i=0;i<n;i++)
    {
        ll temp=i*x;
        for(ll j=1;j<=n;j++)
        {
            int k=j-i;
            if(k<=0)
            {
                temp+=min(b[k+n][n],b[1][j]);
            }
            else temp+=b[k][j];
        }
        ans=min(ans,temp);
    }
    printf("%lld",ans);
    return 0;
}