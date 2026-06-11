#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text, ans = "";
    cin >> text;
    for (char t : text)
    {
        if (t == '0')
        {
            ans += '0';
        }
        else if (t == '1')
        {
            ans += '1';
        }
        else if (t == 'B')
        {
            if (ans.size() == 0)
            {
                continue;
            }
            else
            {
                ans.erase(ans.size()-1);
            }
        }
    }
    cout << ans << endl;
}