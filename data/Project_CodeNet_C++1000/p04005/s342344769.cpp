#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if(a % 2 && b % 2 && c % 2)
    {
        ll l = min(a, min(b, c));
        ll h = max(a, max(b, c));
        ll mid = a + b + c - l - h;
        cout << l * mid << endl;
    }
    else cout << 0 << endl;
}
