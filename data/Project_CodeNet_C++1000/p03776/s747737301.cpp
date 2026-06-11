#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>mp;

ll ara[55];
ll dp[51][53];
ll ncr(ll n,ll r)
{
    if(r>n)return 0;
    if(r==1)return n;
    if(n==r)return 1;
    if(dp[n][r]!=-1)return dp[n][r];
    return dp[n][r]=ncr(n-1,r-1)+ncr(n-1,r);
}
int main()
{
    memset(dp,-1,sizeof dp);
//    cout<<ncr(1,2)<<endl;
    cout<<setprecision(10);
    ll n,a,b;cin>>n>>a>>b;
    for(ll i=0;i<n;i++)
    {
        cin>>ara[i];
        mp[ara[i]]++;
    }
    sort(ara,ara+n);
    ll sum=0;
    ll cnt=0;
    ll last=ara[n-a];
//    cout<<"last = "<<last<<endl;
    for(ll i=n-1;i>=n-a;i--)
    {
        if(ara[i]==last)cnt++;
        sum+=ara[i];
    }
    double avg=sum/double(a);
    ll ans=0;
    if(sum==last*a)         ///same
    {
        for(ll i=a;i<=b;i++)
        {
            ans+=ncr(mp[last],i);
        }
    }
    else
    {
        ans=ncr(mp[last],cnt);
    }
    cout<<avg<<endl<<ans<<endl;
}
/*

    5 2 3
5 5 5 5 5

*/
