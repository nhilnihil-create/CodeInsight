#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;

    int ans = 0;

    if (a == b && a == c && a != 1)
    {
        cout << -1 << endl;
    }
    else
    {
        while(1)
        {
            if (a % 2 || b % 2 || c % 2) break;
            int _a = a, _b = b, _c = c;
            a = (_b + _c) / 2;
            b = (_a + _c) / 2;
            c = (_a + _b) / 2;
            ans++;
        }
    cout << ans << endl;
    }

    
    return 0;
}
