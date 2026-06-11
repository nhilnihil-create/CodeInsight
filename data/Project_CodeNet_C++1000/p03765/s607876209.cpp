#include <bits/stdc++.h>

using namespace std;
int a,b,c,d,q;
string s,t;
int ss[100005],tt[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    for (int i=1; i<(int)s.size(); ++i)
        ss[i] = ss[i-1] + 2 - (s[i]=='A');
    for (int i=1; i<(int)t.size(); ++i)
        tt[i] = tt[i-1] + 2 - (t[i]=='A');
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> c >> d;
        if (((ss[b] - ss[a-1])%3) == ((tt[d] - tt[c-1])%3))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
