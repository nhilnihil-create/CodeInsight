#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = a + b;
    if (ans >= 24)
    {
        ans -= 24;
    }
    cout << ans << endl;
}