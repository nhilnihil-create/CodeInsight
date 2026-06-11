#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
priority_queue <ll> q2;
priority_queue<ll,vector<ll>, greater<ll> > q1;
ll dp[300005][2];
ll a[300005];
int main()
{

    int N;
    scanf("%d",&N);

    for(int i=0;i<3*N;i++)
        scanf("%lld",&a[i]);
    ll sum=0;
    for(int i=0;i<3*N;i++)
    {
        sum+=a[i];
        q1.push(a[i]);
        if(q1.size()>N)
        {
            sum-=q1.top();
            q1.pop();
        }
        dp[i][0]=sum;
    }
    sum=0;
    for(int i=3*N-1;i>=0;i--)
    {
        sum+=a[i];
        q2.push(a[i]);
        if(q2.size()>N)
        {
            sum-=q2.top();
            q2.pop();
        }
        dp[i][1]=sum;
    }
    ll ans=-1e18;
    for(int i=N-1;i<2*N;i++)
    {
        ans=max(ans,dp[i][0]-dp[i+1][1]);
    }
    printf("%lld",ans);

}
