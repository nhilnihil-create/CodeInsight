#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
    {
        long long temp = b + c, temp1 = a + b, temp3 = a + c;
        a = temp;
        b = temp3;
        c = temp1;
        ans++;
        a /= 2;
        b /= 2;
        c /= 2;
        if (ans > 1000000)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}