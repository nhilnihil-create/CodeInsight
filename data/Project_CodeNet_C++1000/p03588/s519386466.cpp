#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int maxi = 0, ans = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (maxi < a)
        {
            ans = a + b;
            maxi = a;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
