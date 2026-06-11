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

    vector<int> ck(26, 0);

    rep(i, s.size())
    {
        ck[s[i] - 'a']++;
    }

    bool ok = true;
    rep(i, 26)
    {
        if (ck[i] & 1)
        {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}
