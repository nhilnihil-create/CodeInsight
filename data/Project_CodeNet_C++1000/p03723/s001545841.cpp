/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    if(a == b && b == c)
    {
        if(a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
            cout << "-1\n";
        else
            cout << "0\n";
        return 0;
    }
    int ans = 0;
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
    {
        ll a1, b1, c1;
        a1 = (b + c) / 2;
        b1 = (a + c) / 2;
        c1 = (a + b) / 2;
        a = a1;
        b = b1;
        c = c1;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
