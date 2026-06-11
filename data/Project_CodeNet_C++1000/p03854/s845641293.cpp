#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
int main()
{
    string S;
    cin >> S;
    vector<string> T = {"dream", "dreamer", "erase", "eraser"};
    reverse(S.begin(), S.end());
    bool s_is_t=true;
    for (int i = 0; i < S.size();)
    {
        bool dividable = false;
        for (string t : T)
        {
            reverse(t.begin(),t.end());
            if (S.substr(i, t.size()) == t)
            {
                i += t.size();
                dividable = true;
            }
        }
        if (!dividable)
        {
            s_is_t=false;
            break;
        }
    }
    if(s_is_t)
    cout << "YES" << endl;
    else cout << "NO" << endl;
}