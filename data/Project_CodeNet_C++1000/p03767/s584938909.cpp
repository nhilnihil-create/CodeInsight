#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define inf 1e18
#define pi acos(-1.0)
#define mod 998244353


int main(void)
{
    fastio;

    int n,i,j;
    cin >> n;
    ll a[4*n],ans=0;
    for(i=0;i<3*n;i++)cin >> a[i];
    sort(a,a+3*n);
    for(i=0,j=3*n-2;i<n;i++,j=j-2)
    {
        ans=ans+a[j];
    }
    cout << ans ;

    return 0;
}
