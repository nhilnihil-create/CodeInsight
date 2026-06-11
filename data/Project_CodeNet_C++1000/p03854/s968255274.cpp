#include <bits/stdc++.h>
using namespace std;

string S;
string t[4] = {"maerd",
               "remaerd",
               "esare",
               "resare"};

int main()
{
    cin >> S;
    reverse(S.begin(), S.end());
    for (int i = 0; i < S.size();)
    {
        bool dividable = false;
        for (int j = 0; j < 4; j++)
        {
            if (S.substr(i, t[j].size()) == t[j])
            {
                dividable = true;
                i += t[j].size();
                break;
            }
        }
        if (!dividable)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
