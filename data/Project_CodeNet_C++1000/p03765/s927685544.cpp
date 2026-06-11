#include <iostream>

using namespace std;

int sr[100'001];
int tr[100'001];

int main()
{
    string s, t;
    cin >> s >> t;

    int n = s.size();
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            sr[i] = tr[i] = 0;
        }
        sr[i] = sr[i - 1] + (s[i - 1] == 'A' ? 1 : 2);
        tr[i] = tr[i - 1] + (t[i - 1] == 'A' ? 1 : 2);
        sr[i] %= 3;
        tr[i] %= 3;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if ((sr[b] - sr[a - 1] + 3) % 3 == (tr[d] - tr[c - 1] + 3) % 3)
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