#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n, ans;
    cin >> n;
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
        ans %= 1000000000 + 7;
    }

    cout << ans << endl;

    return 0;
}