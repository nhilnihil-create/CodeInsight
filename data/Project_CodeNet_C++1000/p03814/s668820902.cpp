#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    string s;
    cin >> s;

    int st, en;

    rep(i, s.size())
    {
        if (s[i] == 'A')
        {
            st = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'Z')
        {
            en = i;
            break;
        }
    }
    cout << en - st + 1 << endl;
    return (0);
}
