#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define int long long
using namespace std;

const int INF = 1e18;
int sum1[100005];
int sum2[100005];
int val[2];

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen("depart.inp", "r", stdin);
//    freopen("depart.out", "w", stdout);

    string s, t;
    cin >> s >> t;

    val[0] = 1;
    val[1] = -1;

    for (int i = 1; i <= s.size(); i++)
        sum1[i] = sum1[i-1] + val[s[i-1] - 'A'];
    for (int i = 1; i <= t.size(); i++)
        sum2[i] = sum2[i-1] + val[t[i-1] - 'A'];



    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = sum1[b] - sum1[a-1];
        int y = sum2[d] - sum2[c-1];
        if (x < 0)
            x = x % 3 + 3;
        if (y < 0)
            y = y % 3 + 3;
        if (x%3 == y%3)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
