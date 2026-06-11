#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    const ll mod=1000000007;
    ll sum=0;
    ll a=0;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin >> x;
        sum=(sum+x)%mod;
        a=(a+i*x-sum)%mod;
    }
    sum=0;
    ll b=0;
    for(int i=1;i<=m;i++)
    {
        ll y;
        cin >> y;
        sum=(sum+y)%mod;
        b=(b+i*y-sum)%mod;
    }
    cout << (a*b)%mod << "\n";
    return 0;
}
