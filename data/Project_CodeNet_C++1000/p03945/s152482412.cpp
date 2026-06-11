#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;

    cin >> s;

    int ans = 0;
    char nc = s[0];
    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] != nc)
        {
            ++ans;
            nc = s[i];
        }
    }

    cout << ans << endl;

    return 0;
}

