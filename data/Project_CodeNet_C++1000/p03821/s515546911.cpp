#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[100010],b[100010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];

    ll ans=0;

    for(int i=n-1;i>=0;i--)
    {
        ans+=(b[i]-(a[i]+ans)%b[i])%b[i];
    }

    cout<<ans<<"\n";

    return 0;
}
