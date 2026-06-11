#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int sa[MAXN + 1];
int sb[MAXN + 1];
int ta[MAXN + 1];
int tb[MAXN + 1];

int main()
{
    string s, t;
    int q;
    cin >> s >> t >> q;
    int n = (int) s.length();
    int m = (int) t.length();
    for (int i = 1; i <= n; i++)
    {
        sa[i] = sa[i - 1] + (s[i - 1] == 'A');
        sb[i] = sb[i - 1] + (s[i - 1] == 'B');
    }
    for (int i = 1; i <= m; i++)
    {
        ta[i] = ta[i - 1] + (t[i - 1] == 'A');
        tb[i] = tb[i - 1] + (t[i - 1] == 'B');
    }
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int amod = ((sa[b] - sa[a - 1]) % 3 - (ta[d] - ta[c - 1]) % 3 + 3) % 3;
        int bmod = ((sb[b] - sb[a - 1]) % 3 - (tb[d] - tb[c - 1]) % 3 + 3) % 3;
        int nmod = ((b - a) % 3 - (d - c) % 3 + 3) % 3;
        if (amod == bmod && (amod + nmod) % 3 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
