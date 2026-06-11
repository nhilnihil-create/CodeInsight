#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string o, e;
    cin >> o >> e;
    string ans;
    ans.resize(o.length() + e.length());
    for (size_t i = 0; i < o.length(); i++)
    {
        ans[2 * i] = o[i];
    }
    for (size_t i = 0; i < e.length(); i++)
    {
        ans[2 * i + 1] = e[i];
    }
    cout << ans << endl;

    return 0;
}