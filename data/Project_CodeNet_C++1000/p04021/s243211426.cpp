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
    map<int,int>mp;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]=i;
    }
    sort(a,a+n);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int dif=mp[a[i]]-i;
        dif=abs(dif);
        ans+=dif%2;
    }
    cout<<ans/2;
}
