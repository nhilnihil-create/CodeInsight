// https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_b

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, a, b;
    string s;

    cin >> n >> a >> b >> s;

    a += b;

    bool cond;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            cond = a > 0;
            a--;
        }
        if (s[i] == 'b')
        {
            cond = (a > 0) & (b > 0);
            if (cond)
            {
                a--;
                b--;
            }
        }
        if (s[i] == 'c')
        {
            cond = false;
        }
        cout << (cond ? "Yes" : "No") << endl;
    }
    return 0;
}
