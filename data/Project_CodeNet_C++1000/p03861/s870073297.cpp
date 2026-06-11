#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll a,b,x;
    cin >> a >> b >> x;
    ll ans1 = a / x;
    ll ans2 = b / x;
    ll ans = ans2 - ans1;
    if(a % x == 0)
    {
        ans++;
    }
    cout << ans;
}
