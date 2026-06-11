#include <bits/stdc++.h>
using namespace std;

int main()
{

    long a, b, x;
    cin >> a >> b >> x;

    long ans = (b / x) - (a / x);

    if (a % x == 0)
    {
        ans++;
    }
    cout << ans << endl;

    return 0;
}