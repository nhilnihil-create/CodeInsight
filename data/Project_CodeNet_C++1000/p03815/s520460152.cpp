#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
    ll x;
    cin >> x;
    ll ans = x/11 * 2;
    x %= 11;
    if(x > 6)
    {
      ans += 2;
    }
    else if (x > 0)
    {
        ans++;
    }

    cout << ans << endl;
}
