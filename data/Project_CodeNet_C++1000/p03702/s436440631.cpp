#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ispossible(ll n, ll a, ll b, ll turns, vector <ll> &h)
{
    ll offset = b * turns;

    for(ll i = 0; i < n; i++)
    {   
        ll x = h[i];
        x -= offset;

        if(x > 0)
        {
            ll cturns = 1 + ((x - 1) / (a - b));

            if(cturns > turns)
                return false;

            turns -= cturns;    
        }
    }

    return true;
}

ll solve(ll n, ll a, ll b, vector <ll> &h)
{
    ll lo = 1, hi = 1e9;

    while(lo < hi)
    {
        ll mid = (lo + hi) / 2;
        bool possible = ispossible(n, a, b, mid, h);

        if(possible)
            hi = mid;
        else
            lo = mid + 1;    
    }

    return lo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, a, b;
    cin >> n >> a >> b;
    vector <ll> h(n);

    for(ll i = 0; i < n; i++)
        cin >> h[i];

    cout << solve(n, a, b, h) <<"\n";  
    // cout << ispossible(n, a, b, 3, h) <<"\n";   
    return 0;
}
