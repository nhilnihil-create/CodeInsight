#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>a[i];

    int ans=0;

    for(int i=0;i<n;i++)if(a[a[i]-1]==i+1)ans++;

    ans/=2;

    cout<<ans<<"\n";

    return 0;
}
