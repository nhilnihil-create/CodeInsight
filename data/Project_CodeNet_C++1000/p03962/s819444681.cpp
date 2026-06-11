#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, ans;
    ans = 1;
    cin >> a >> b >> c;
    if (a != b)
    {
        ans++;
    }
    if (a != c && b != c)
    {
        ans++;
    }
    cout << ans << endl;
    return 0;
}