#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vp vector<pair<int, int>>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50
#define PI 3.141592653589793238462643383279502884197169

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

   ////////////////////////  END OF TEMPLATE ////////////////////////////////////////

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int, int> mp;
    while(n--)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(auto x: mp)
    {
        if(x.second % 2 == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
