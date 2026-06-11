#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    string s;
    cin >> s;

    string res = "";
    rep(i, s.size())
    {
        if (s[i] == 'B')
        {
            if (res.empty())
            {
                continue;
            }
            res.pop_back();
        }
        else
        {
            res.push_back(s[i]);
        }
    }

    cout << res << '\n';
    return 0;
}
