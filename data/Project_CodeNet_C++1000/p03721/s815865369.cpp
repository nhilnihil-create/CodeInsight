#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define inf 1000000100

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    map<int, ll> mp;
    int ans = -1;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    for(auto x: mp)
    {
        if (k - x.second <= 0)
        {
            ans = x.first;
            break;
        }
        k -= x.second;
    }
    cout << ans << endl;
}
