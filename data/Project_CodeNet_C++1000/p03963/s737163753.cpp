#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;
    cin>>n>>k;

    ll ans=k;

    for(int i=1;i<n;i++)ans*=(k-1);

    cout<<ans<<"\n";

    return 0;
}
