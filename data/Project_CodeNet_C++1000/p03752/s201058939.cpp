#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define LL_HALFMAX 9223372036854775807 / 2	

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll>a(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll result = LL_HALFMAX;
    ll addcost = 0;
    for(ll bit = 0; bit <(1<<n); bit++)
    {
        ll cost = 0;
        ll look = 0;
        ll hmax = a[0] - 1;
        for(ll i = 0; i < n; i++)
        {
            if(a[i] > hmax)
            {
                hmax = a[i];
                look++;
            }
            else if(bit&(1<<i))
            {
                addcost = hmax - a[i] + 1;
                look++;
                hmax += 1;
                cost += addcost;
            }
        }
        if(look >= k)
        {
            result = min(result,cost);
        }
    }
    cout << result << endl;
    return 0;
}
