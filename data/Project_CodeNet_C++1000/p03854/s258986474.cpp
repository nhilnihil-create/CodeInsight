#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    string d1 = "dreameraser";
    string d2 = "dreamerase";
    string d3 = "dreamer";
    string d4 = "dream";
    string r1 = "eraser";
    string r2 = "erase";
    bool ans = 1;
    for (int i = 0; i < (int)s.size();)
    {
        if (s[i] == 'd')
        {
            if (s.substr(i, d1.size()) == d1)
                i += d1.size();
            else if (s.substr(i, d2.size()) == d2)
                i += d2.size();
            else if (s.substr(i, d3.size()) == d3)
                i += d3.size();
            else if (s.substr(i, d4.size()) == d4)
                i += d4.size();
            else
            {
                ans = 0;
                break;
            }
        }
        else if (s[i] == 'e')
        {
            if (s.substr(i, r1.size()) == r1)
                i += r1.size();
            else if (s.substr(i, r2.size()) == r2)
                i += r2.size();
            else
            {
                ans = 0;
                break;
            }
        }
        else
        {
            ans = 0;
            break;
        }
    }

    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
