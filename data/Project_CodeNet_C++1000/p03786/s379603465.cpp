#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    sort(a.begin(),a.end());

    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1]*2)ans=i;
        a[i]+=a[i-1];
    }

    cout<<n-ans<<"\n";

    return 0;
}
