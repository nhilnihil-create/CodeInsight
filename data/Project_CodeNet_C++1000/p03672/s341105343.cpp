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

    for (int i = s.size() - 1; i >= 0; i--)
    {
        string t = s.substr(0, i);
        int n = t.size();
        if (n & 1)
            continue;

        if (t.substr(0, n / 2) == t.substr(n / 2))
        {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
