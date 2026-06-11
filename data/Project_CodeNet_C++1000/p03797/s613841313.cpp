#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = min(n, m/2);
    if(m/2 > n)
    {
        ans += ((m/2) - n)/2;
    }

    cout << ans << endl;
}
