#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    string divider[4] = {"dream", "dreamer", "erase", "eraser"};

    rep(i, 4)
    {
        reverse(divider[i].begin(), divider[i].end());
    }

    string S;
    cin >> S;

    reverse(S.begin(), S.end());

    bool can_divide = true;
    for (int i = 0; i < S.length();)
    {
        bool can_divide_by_i = false;
        for (int j = 0; j < 4; j++)
        {
            if (S.substr(i, divider[j].length()) == divider[j])
            {
                can_divide_by_i = true;
                i += divider[j].length();
            }
        }
        if (can_divide_by_i == false)
        {
            can_divide = false;
            break;
        }
    }

    if (can_divide)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}