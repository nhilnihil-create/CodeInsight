#include <bits/stdc++.h>

using namespace std;
const int Nmax = 1e5 + 5;

int cnts[Nmax][2];
int cntt[Nmax][2];
int q,a,b,c,d;

int main()
{
    //freopen("file.inp","r",stdin);
    string s,t;
    cin >> s;
    cin >> t;
    for (int i = 1; i <= s.size(); i++)
    {
        if (s[i - 1] == 'A') cnts[i][0]++;
        else cnts[i][1]++;
        cnts[i][0] += cnts[i - 1][0];
        cnts[i][1] += cnts[i - 1][1];
    }
    for (int i = 1; i <= t.size(); i++)
    {
        if (t[i - 1] == 'A') cntt[i][0]++;
        else cntt[i][1]++;
        cntt[i][0] += cntt[i - 1][0];
        cntt[i][1] += cntt[i - 1][1];
    }
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> c >> d;
        int cnta,cntb;
        int S, T;
        cnta = cnts[b][0] - cnts[a - 1][0];
        cntb = cnts[b][1] - cnts[a - 1][1];
        if (cnta > cntb)
        {
            cnta -= cntb;
            cnta %= 3;
            S = cnta;
        } else {
            cntb -= cnta;
            cntb %= 3;
            S = (3 - cntb) % 3;
        }
        cnta = cntt[d][0] - cntt[c - 1][0];
        cntb = cntt[d][1] - cntt[c - 1][1];
        if (cnta > cntb)
        {
            cnta -= cntb;
            cnta %= 3;
            T = cnta;
        } else {
            cntb -= cnta;
            cntb %= 3;
            T = (3 - cntb) % 3;
        }
        if (S == T) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
