#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
main()
{
    int n;
    cin>>n;
    ll a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    ll ans=0,ex=0;
    for(int i=n-1;i>=0;i--)
    {
        ll x=a[i]+ans;
        ll y=b[i];
        if(x%y==0)
        {
            ;
        }
        else
        {
            ll d=((x/y)+1)*y;
            ans+=d-x;
        }
    }
    cout<<ans;

}
