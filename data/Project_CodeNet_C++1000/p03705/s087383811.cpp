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

    ll n,a,b,l,r;
    cin >> n >> a >> b;
    l=(n-1)*a+b;
    r=(n-1)*b+a;

    if(n==1&&a!=b)cout << "0";
    else if(a>b)cout << "0";
    else
    {
        cout << r-l+1;
    }

    return 0;
}
