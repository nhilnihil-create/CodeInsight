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
    string s;
    cin >> s;
    int a[4] = {0};
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == 'N')
        {
            a[0] = 1;
        }
        if (s[i] == 'S')
        {
            a[1] = 1;
        }
        if (s[i] == 'E')
        {
            a[2] = 1;
        }
        if (s[i] == 'W')
        {
            a[3] = 1;
        }
    }
    if ((a[0] ^ a[1]) == 0 && (a[2] ^ a[3]) == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {

        cout << "No" << endl;
    }

    return 0;
}