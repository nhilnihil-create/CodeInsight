#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100005;

int n, m;
string s, t;
int psS[MaxN], psT[MaxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> t;
    n = s.length(), m = t.length();
    psS[0] = psT[0] = 0;
    for (int i = 0; i < n; i++)
    {
        psS[i + 1] = psS[i] + s[i] - 'A' + 1;
    }
    for (int i = 0; i < m; i++)
    {
        psT[i + 1] = psT[i] + t[i] - 'A' + 1;
    }
    int q, a, b, c, d;
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> c >> d;
        cout << ((psS[b] - psS[a - 1]) % 3 == (psT[d] - psT[c - 1]) % 3 ? "YES\n" : "NO\n");
    }
    return 0;
}
