#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    ll ans=0;

    vector<int> a(3*n);

    for(int i=0;i<3*n;i++)cin>>a[i];

    sort(a.begin(),a.end(),greater<int>());

    for(int i=0;i<n;i++)ans+=a[2*i+1];

    cout<<ans<<"\n";

    return 0;
}
