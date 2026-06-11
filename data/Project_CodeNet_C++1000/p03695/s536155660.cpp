#include <bits/stdc++.h>
using namespace std;

int n, ans, mindiff;
bool color[] = {false, false, false, false, false, false, false, false};

int main()
{
    cin >> n;

    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        if (a <= 399)
        {
            color[0] = true;
        }
        else if (a >= 400 && a <= 799)
        {
            color[1] = true;
        }
        else if (a >= 800 && a <= 1199)
        {
            color[2] = true;
        }
        else if (a >= 1200 && a <= 1599)
        {
            color[3] = true;
        }
        else if (a >= 1600 && a <= 1999)
        {
            color[4] = true;
        }
        else if (a >= 2000 && a <= 2399)
        {
            color[5] = true;
        }
        else if (a >= 2400 && a <= 2799)
        {
            color[6] = true;
        }
        else if (a >= 2800 && a <= 3199)
        {
            color[7] = true;
        }
        else
        {
            ans++;
        }
    }

    for (bool i : color)
    {
        if (i)
        {
            mindiff++;
        }
    }

    ans += mindiff;
    if (mindiff == 0)
    {
        mindiff++;
    }
    cout << mindiff << ' ' << ans << endl;
}
