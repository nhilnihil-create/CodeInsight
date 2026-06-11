#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll a,b,c;
    cin>>a>>b>>c;

    ll ans=(a%2==0||b%2==0||c%2==0?0:min(min(a*b,b*c),c*a));

    cout<<ans<<"\n";

    return 0;
}
