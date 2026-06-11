#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int start = 0;
    int end = 0;
    int ans = 0;

    if (d <= a)
    {
        cout << 0 << endl;
        return 0;
    }
    else if (b <= c)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        start = max(a, c);
        end = min(b, d);
        ans = end - start;
        cout << ans << endl;
        return 0;
    }
}