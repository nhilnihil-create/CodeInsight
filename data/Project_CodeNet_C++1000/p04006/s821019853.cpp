#include <iostream>
#include <algorithm>
using namespace std;
//const ll llf=(1ll<<63)-1;
typedef long long ll;
const ll llf=(1ll<<63)-1;
ll dp[2010][2010];ll a[2010];
int main()
{
    ll n,x;
    cin>>n>>x;
    int i;
    for(i=1;i<=n;i++)
        cin>>a[i];
    int k;
    for(i=1;i<=n;i++)
        dp[i][0]=a[i];
    for(k=1;k<n;k++)
    {
        for(i=1;i<=n;i++)
        {
            int temp=i-k;
            if(temp<=0) temp+=n;
            dp[i][k]=min(dp[i][k-1],(ll)a[temp]);
        }
    }
    ll sum=0;ll ans=llf;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(int j=1;j<=n;j++)
            sum+=dp[j][i];
        sum+=i*x;
        ans=min(ans, sum);
    }
    cout<<ans<<endl;
    return 0;
}