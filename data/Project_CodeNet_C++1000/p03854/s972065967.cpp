#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    string s;
    cin >> s;
    vector<string> str = {"dream", "dreamer", "erase", "eraser"};
    reverse(all(s));
    rep(i, 4)
    {
        reverse(all(str[i]));
    }

    string ans = "NO";
    for (int i = 0; i < s.size();)
    {
        bool ok = false;
        rep(j, 4)
        {
            if (s.substr(i, str[j].size()) == str[j])
            {
                i += str[j].size();
                ok = true;
            }
        }
        if (!ok)
        {
            break;
        }
        if (i == s.size())
        {
            ans = "YES";
        }
    }

    cout << ans << endl;
    return 0;
}
