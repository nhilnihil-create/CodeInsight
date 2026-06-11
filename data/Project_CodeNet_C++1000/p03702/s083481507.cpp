#include <bits/stdc++.h>
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef long long ll;
const int maxn = 1e5+100;
ll a[maxn];
ll n,A,B;

bool check(ll res)
{
    ll num = 0;
    for(int i = 1; i <= n; i++)
    {
        ll tmp = a[i]-res*B;
        if(tmp>0)
        {
            num += (tmp-1)/(A-B)+1;
        }
    }
    if(num>res) return false;
    else return true;
}

int main()
{
    ios::sync_with_stdio(false);

    cin>>n>>A>>B;
    ll l = 1;
    ll r = 0;
    for(int i = 1; i <=n ;i++ )
    {
        cin>>a[i];
        r += a[i]/B+1;
    }

    ll ans;
    while(l<r)
    {
        ll mid = l+r>>1;
        if(check(mid))
        {
            r = mid;
            ans = mid;
        }
        else
        {
            l = mid+1;
        }
    }
    cout<<ans<<"\n";
}
