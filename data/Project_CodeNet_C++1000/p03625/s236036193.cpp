#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vp vector<pair<int, int>>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

ll gcd(ll a, ll b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a/g * b; //prevent overflow
}

/////////////////////////  END OF TEMPLATE ////////////////////////////////////////


int main()
{
    int n;
    cin >> n;
    vll v;
    for(int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        v.pb(a);
    }

    sort(v.rbegin(), v.rend());
    ll first = 0, second = 0, c = 0;
    for(int i = 1; i < n; ++i)
    {
        if(v[i] == v[i-1])
        {
            if(c == 0)
            {
                first = v[i];
            }
            else
            {
                second = v[i];
            }
            c++;
            i++;
            if(c == 2)
            {
                break;
            }
        }
    }

    if(c == 2)
    {
        ll ans = first*second;
        cout << ans << endl;
    }
    else
    {
        cout << 0 << endl;
    }

}
