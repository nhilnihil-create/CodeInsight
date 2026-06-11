#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main()
{
    string s;
    cin >> s;
    if(s[s.size() - 2] == s[s.size() - 1])
    {
        cout << s.size() - 1 << " " << s.size() << "\n";
        return 0;
    }
    for(int i = 0;i + 2 < s.size();i++)
    {
        if(s[i] == s[i + 1])
        {
            cout << i + 1 << " " << i + 2 << "\n";
            return 0;
        }
        else if(s[i] == s[i + 2])
        {
            cout << i + 1 << " " << i + 3 << "\n";
            return 0;
        }
    }
    cout << "-1 -1\n";

    return 0;
}