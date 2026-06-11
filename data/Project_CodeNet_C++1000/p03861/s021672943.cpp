#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long

int main()
{
    int cases, n;
    ll sum = 0, cnt = 0, a, b, c, x, f2;
    bool flag = false;



    cin >> a >> b >> x;

    ll f1 = b/x;

    if( a <= 1) f2 = 0;
    else f2 = (a-1)/x;

    ll ans = f1 - f2;
    if( ans < 0)ans = 0;

    if( a == 0 || b == 0)ans++;

    cout << ans << endl;



    return 0;
}

