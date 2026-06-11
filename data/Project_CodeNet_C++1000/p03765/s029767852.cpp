#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
int main()
{
    string s, t;
    cin >> s >> t;
    vector<int> imoss;
    vector<int> imost;
    imoss.push_back(0);
    imost.push_back(0);
    rep(i, t.length())
    {
        if (t[i] == 'A')
        {
            imost.push_back(imost[i] + 1);
        }
        else
        {
            imost.push_back(imost[i] + 2);
        }
    }
    rep(i, s.length())
    {
        if (s[i] == 'A')
        {
            imoss.push_back(imoss[i] + 1);
        }
        else
        {
            imoss.push_back(imoss[i] + 2);
        }
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((imoss[b] - imoss[a - 1]) % 3 == (imost[d] - imost[c - 1]) % 3)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}