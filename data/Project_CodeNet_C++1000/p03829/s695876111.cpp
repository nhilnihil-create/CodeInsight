#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[100005];
int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)cin>>ara[i];
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        int val=ara[i]-ara[i-1];
        ans+=min(val*a,b);
    }
    cout<<ans<<endl;
}
