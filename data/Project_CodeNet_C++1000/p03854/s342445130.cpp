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
    reverse(all(s));

    vector<string> t = {
        "dream",
        "dreamer",
        "erase",
        "eraser"};
    rep(i, t.size()) { reverse(all(t[i])); }

    int n = 0;
    bool ans = 1;
    while (n != s.size())
    {
        bool flag = 0;
        int tmp = 0;
        rep(i, 4)
        {
            if (s.substr(n, t[i].size()) == t[i])
            {
                flag = 1;
                tmp = i;
            }
        }
        if (flag)
        {
            n += t[tmp].size();
        }
        else
        {
            ans = 0;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}
