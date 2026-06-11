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
    return a/g * b;
}

int main()
{
    int n;
    cin >> n;
    vll data;
    while(n--)
    {
        ll t;
        cin >> t;
        data.pb(t);
    }
    ll ans = 1;
    for(int i = 0; i < data.size(); ++i)
    {
        ans = lcm(ans, data[i]);
    }

    cout << ans << endl;
}
