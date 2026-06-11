#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
using ll = long long;

ll t[100010],a[100010];
ll st[100010],sa[100010];
ll s[100010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>t[i];
    for(int i=0;i<n;i++)cin>>a[i];

    if(t[n-1]!=a[0])
    {
        cout<<0<<"\n";
        return 0;
    }

    ll b=0;
    int it=0;
    for(int i=0;i<n;i++)
    {
        if(t[i]>b)
        {
            b=t[i];
            st[i]=1;
            it=i;
        }
        else st[i]=t[i];
    }

    b=0;
    int ia=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>b)
        {
            b=a[i];
            sa[i]=1;
            ia=i;
        }
        else sa[i]=a[i];
    }

    if(it>ia)
    {
        cout<<0<<"\n";
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        s[i]=min(st[i],sa[i]);
    }

    ll ans=1;

    for(int i=0;i<n;i++)
    {
        ans*=s[i];
        ans%=MOD;
    }

    cout<<ans<<"\n";

    return 0;
}
