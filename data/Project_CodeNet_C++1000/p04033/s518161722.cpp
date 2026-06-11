#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll a, b;

int main()
{
    cin >> a >> b;
    int ans;
    if (b > 0 && a > 0)
    {
        ans = 1;
    }
    else if (b >= 0 && a <= 0)
    {
        ans = 0;
    }

    if (a < 0 && b < 0)
    {
        if ((b - a) % 2 == 0)
        {
            ans = -1;
        }
        else
        {
            ans = 1;
        }
    }

    if (ans == 1)
    {
        cout << "Positive" << endl;
    }
    if (ans == 0)
    {
        cout << "Zero" << endl;
    }
    if (ans == -1)
    {
        cout << "Negative" << endl;
    }
    return 0;
}
