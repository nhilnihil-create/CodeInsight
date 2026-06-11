#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    string ans;
    if (s[0] == s[s.size() - 1])
    {
        if (s.size() % 2 == 0)
            ans += "First";
        else
            ans += "Second";
    }
    else
    {
        if (s.size() % 2 == 0)
            ans += "Second";
        else
            ans += "First";
    }
    cout << ans << endl;
}
