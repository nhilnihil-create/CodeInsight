#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define MOD 1000000007

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    ll ans=1;

    for(int i=1;i<=n;i++)
    {
        ans*=i;
        ans%=MOD;
    }

    cout<<ans<<"\n";

    return 0;
}
