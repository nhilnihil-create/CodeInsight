#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
ll a[55];
map<ll,ll>mp;
ll ncr(ll n,ll r)
{
    ll i,j,s,p,m,l,g;
    s=p=1ll;
    l=max(r,(n-r));
    m=min(r,(n-r));
    for(i=l+1ll,j=2ll; i<=n || j<=m; i++,j++)
    {
        if(i<=n)
        {
            s*=i;
        }
        if(j<=m)
        {
            p*=j;
        }
        g=__gcd(s,p);
        s/=g;
        p/=g;
    }
    s/=p;
    return s;
}
int main()
{
    ft
    ll t,i,j,n,m,l,r,s=0ll,p,q,ans=0ll;
    cin>>n>>l>>r;
    for(i=0ll; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater<ll>());
    m=LLONG_MAX;
    for(i=0ll; i<l; i++)
    {
        m=min(m,a[i]);
        s+=a[i];
        mp[a[i]]++;
    }
    cout<<fixed<<setprecision(6)<<(double)(s*1.0/l)<<"\n";
    p=0ll;
    for(i=0ll; i<n; i++)
    {
        if(a[i]==m)
        {
            p++;
        }
    }
    if(m!=a[0])
    {
        ans+=ncr(p,mp[m]);
    }
    else
    {
        for(i=l-1ll;i<r && a[i]==m;i++)
        {
            ans+=ncr(p,i+1ll);
        }
    }
    cout<<ans<<"\n";
    return 0;
}